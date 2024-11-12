#include "ModuloVentas.h"
#include "ModuloInventario.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

void ModuloVentas::mostrarMenuVentas() {
    int opcion;
    do {
        cout << "\n=== Menú de Ventas ===\n";
        cout << "1. Venta de Producto\n";
        cout << "2. Finalizar Venta\n";
        cout << "3. Cancelar Venta\n";
        cout << "4. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVenta();
                break;
            case 2:
                finalizarVenta();
                break;
            case 3:
                cancelarVenta();
                break;
            case 4:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 4);
}

void ModuloVentas::registrarVenta() {
    //subtotal = 0;
    int categoriaId, cantidad;
    string productoNombre;
    bool continuar = true;

    while (continuar) {
        listarCategorias();

        cout << "Seleccione el ID de la categoría (0 para terminar): ";
        cin >> categoriaId;
        if (categoriaId == 0) break;

        listarProductosPorCategoria(categoriaId);

        cout << "Ingrese el nombre del producto: ";
        cin.ignore();
        getline(cin, productoNombre);

        cout << "Ingrese la cantidad deseada: ";
        cin >> cantidad;

        // Buscar el producto en el inventario por ID de categoría
        ifstream file("inventario.txt");
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo de inventario.\n";
            return;
        }

        Producto productoEncontrado("", categoriaId, 0, 0);
        string line;
        bool productoExiste = false;
        while (getline(file, line)) {
            Producto producto = Producto::fromString(line);
            if (producto.nombre == productoNombre && producto.categoriaId == categoriaId) {
                productoEncontrado = producto;
                productoExiste = true;
                break;
            }
        }
        file.close();

        if (productoExiste) {
            if (cantidad <= productoEncontrado.stock) {
                ItemVenta item{productoEncontrado, cantidad};
                itemsVenta.push_back(item);
                subtotal += productoEncontrado.precio * cantidad;

                // Actualizar el stock del producto en el archivo de inventario
                actualizarStockProducto(productoEncontrado.nombre, productoEncontrado.categoriaId, -cantidad);

                cout << "Producto agregado a la venta.\n";
            } else {
                cout << "Stock insuficiente para el producto seleccionado.\n";
            }
        } else {
            cout << "Producto no encontrado en la categoría seleccionada.\n";
        }

        cout << "¿Desea agregar otro producto? (1: Sí, 0: No): ";
        cin >> continuar;
    }
}
void ModuloVentas::actualizarStockProducto(const string& nombre, int categoriaId, int cantidad) {
    ifstream file("inventario.txt");
    ofstream tempFile("temp.txt");

    if (!file.is_open() || !tempFile.is_open()) {
        cerr << "Error al abrir los archivos.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        Producto producto = Producto::fromString(line);
        if (producto.nombre == nombre && producto.categoriaId == categoriaId) {
            producto.stock += cantidad;  // Actualizamos el stock
            // Escribimos el producto actualizado en el archivo temporal sin añadir un salto extra
            tempFile << producto.toString();
            found = true;
        } else {
            // Escribimos las líneas del archivo original sin cambios
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    if (found) {
        // Eliminamos el archivo original y renombramos el archivo temporal
        remove("inventario.txt");
        rename("temp.txt", "inventario.txt");
    } else {
        remove("temp.txt");
        cerr << "Producto no encontrado en el inventario.\n";
    }
}

// Nueva función para cargar categorías desde categorias.txt en ModuloVentas
vector<Categoria> ModuloVentas::cargarCategoriasVentas() {
    vector<Categoria> categoriasVentas;
    ifstream file("categorias.txt");

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de categorías.\n";
        return categoriasVentas;  // Devuelve el vector vacío si no se puede abrir el archivo
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, nombre;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');

        int id = stoi(idStr);
        categoriasVentas.push_back(Categoria(id, nombre));
    }

    file.close();
    return categoriasVentas;
}

void ModuloVentas::listarCategorias() {
    // Llama a cargarCategoriasVentas para obtener las categorías
    vector<Categoria> categorias = cargarCategoriasVentas();
    cout << "\n--- Categorías ---\n";
    for (const auto& categoria : categorias) {
        cout << "ID: " << categoria.id << ", Nombre: " << categoria.nombre << endl;
    }
}

void ModuloVentas::listarProductosPorCategoria(int categoriaId) {
    ifstream file("inventario.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de inventario.\n";
        return;
    }

    cout << "\n--- Productos de la Categoría ---\n";
    string line;
    while (getline(file, line)) {
        Producto producto = Producto::fromString(line);
        if (producto.categoriaId == categoriaId) {
            cout << "Producto: " << producto.nombre << ", Precio: " << producto.precio << ", Stock: " << producto.stock << endl;
        }
    }
    file.close();
}

void ModuloVentas::finalizarVenta() {
    if (itemsVenta.empty()) {
        cout << "No hay productos en la venta actual.\n";
        return;
    }

    total = subtotal;
    string fechaActual = obtenerFechaActual();

    // Mostrar resumen de la venta
    cout << "\n=== Resumen de la Venta ===\n";
    for (const auto& item : itemsVenta) {
        cout << "Producto: " << item.producto.nombre
             << ", Cantidad: " << item.cantidad
             << ", Subtotal: $" << item.producto.precio * item.cantidad << endl;
    }
    cout << "Total de la Venta: $" << total << "\n";

    // Guardar la venta en el archivo ventas.txt
    for (const auto& item : itemsVenta) {
        Venta venta(fechaActual, item.producto.nombre, item.cantidad, item.producto.precio, item.producto.precio * item.cantidad);
        guardarVentaEnArchivo(venta);
    }

    itemsVenta.clear();
    subtotal = 0;
    total = 0;
    cout << "Venta finalizada y registrada exitosamente.\n";
}

void ModuloVentas::cancelarVenta() {
    itemsVenta.clear();
    subtotal = 0;
    total = 0;
    cout << "Venta cancelada.\n";
}

void ModuloVentas::guardarVentaEnArchivo(const Venta& venta) {
    ofstream file("ventas.txt", ios::app);
    if (file.is_open()) {
        file << venta.fecha << "," << venta.producto << "," << venta.cantidad << "," << venta.precioUnitario << "," << venta.total << "\n";
        file.close();
    } else {
        cerr << "Error al abrir el archivo de ventas.\n";
    }
}

string ModuloVentas::obtenerFechaActual() {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
    return string(buffer);
}
