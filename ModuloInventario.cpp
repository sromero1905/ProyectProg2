#include "ModuloInventario.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Definición de variables globales
vector<Categoria> categorias;
int siguienteIdCategoria = 1;

// Constructor de Producto
Producto::Producto(string nombre, int categoriaId, double precio, int stock)
    : nombre(nombre), categoriaId(categoriaId), precio(precio), stock(stock) {}

// Método para convertir un producto a string
string Producto::toString() const {
    return nombre + "," + to_string(categoriaId) + "," + to_string(precio) + "," + to_string(stock) + "\n";
}

// Método para convertir un string a un producto
Producto Producto::fromString(const string& data) {
    stringstream ss(data);
    string nombre, categoriaIdStr, precioStr, stockStr;

    getline(ss, nombre, ',');
    getline(ss, categoriaIdStr, ',');
    getline(ss, precioStr, ',');
    getline(ss, stockStr, ',');

    int categoriaId = stoi(categoriaIdStr);
    double precio = stod(precioStr);
    int stock = stoi(stockStr);

    return Producto(nombre, categoriaId, precio, stock);
}

// Función para agregar un nuevo producto
void agregarProducto() {
    string nombre;
    int categoriaId;
    double precio;
    int stock;

    cout << "Ingrese nombre del producto: ";
    cin.ignore();
    getline(cin, nombre);

    // Consultar categorías
    listarCategorias();
    cout << "Seleccione ID de la categoria: ";
    cin >> categoriaId;

    cout << "Ingrese precio del producto: ";
    cin >> precio;
    cout << "Ingrese stock inicial: ";
    cin >> stock;

    Producto nuevoProducto(nombre, categoriaId, precio, stock);

    // Guardar el producto en el archivo
    ofstream file("inventario.txt", ios::app);
    if (file.is_open()) {
        file << nuevoProducto.toString();
        file.close();
        cout << "Producto agregado exitosamente.\n";
    } else {
        cerr << "Error al abrir el archivo.\n";
    }
}

// Función para agregar una nueva categoría
void agregarCategoria() {
    string nombre;
    cout << "Ingrese el nombre de la nueva categoria: ";
    cin.ignore();
    getline(cin, nombre);

    // Crear nueva categoría y agregarla al vector
    Categoria nuevaCategoria(siguienteIdCategoria++, nombre);
    categorias.push_back(nuevaCategoria);

    // Guardar la categoría en el archivo
    ofstream file("categorias.txt", ios::app);
    if (file.is_open()) {
        file << nuevaCategoria.id << "," << nuevaCategoria.nombre << endl;
        file.close();
        cout << "Categoria agregada exitosamente.\n";
    } else {
        cerr << "Error al abrir el archivo de categorias.\n";
    }
}

// Función para listar las categorías disponibles
void listarCategorias() {
    cout << "\n--- Categorías ---\n";
    for (const auto& categoria : categorias) {
        cout << "ID: " << categoria.id << ", Nombre: " << categoria.nombre << endl;
    }
}

// Función para cargar las categorías desde el archivo
void cargarCategorias() {
    ifstream file("categorias.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de categorias.\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, nombre;
        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        try {
            int id = stoi(idStr);
            categorias.push_back(Categoria(id, nombre));
            // Actualiza el siguiente ID si es necesario
            if (id >= siguienteIdCategoria) {
                siguienteIdCategoria = id + 1;
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            cerr << "El ID de categoría '" << idStr << "' no es válido." << endl;
        }
    }
    file.close();
}

// Función para consultar el stock de productos
void consultarStock() {
    ifstream file("inventario.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }

    vector<Producto> productos;
    string line;
    while (getline(file, line)) {
        productos.push_back(Producto::fromString(line));
    }
    file.close();

    int opcion;
    cout << "1. Filtrar por nombre\n";
    cout << "2. Filtrar por categoria\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1) {
        string nombre;
        cout << "Ingrese el nombre del producto: ";
        getline(cin, nombre);

        for (const auto& producto : productos) {
            if (producto.nombre == nombre) {
                cout << "Producto: " << producto.nombre << ", Stock: " << producto.stock << endl;
            }
        }
    } else if (opcion == 2) {
        // Listar categorías antes de solicitar el ID
        listarCategorias();

        int categoriaId;
        cout << "Ingrese el ID de la categoria: ";
        cin >> categoriaId;

        for (const auto& producto : productos) {
            if (producto.categoriaId == categoriaId) {
                cout << "Producto: " << producto.nombre << ", Stock: " << producto.stock << endl;
            }
        }
    } else {
        cout << "Opción no válida.\n";
    }
}

// Función principal para gestionar el inventario
void gestionarInventario() {
    cargarCategorias();
    int opcion;
    do {
        cout << "\n=== Menú de Inventario ===\n";
        cout << "1. Agregar Producto\n";
        cout << "2. Agregar Categoria\n";
        cout << "3. Consultar Stock\n";
        cout << "4. Listar Categorías\n";
        cout << "5. Regresar al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: agregarCategoria(); break;
            case 3: consultarStock(); break;
            case 4: listarCategorias(); break;
            case 5: break; // Regresar
            default: cout << "Opción no válida.\n"; break;
        }
    } while (opcion != 5);
}
