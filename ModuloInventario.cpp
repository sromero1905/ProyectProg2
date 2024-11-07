// ModuloInventario.cpp
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
Producto::Producto(string nombre, string descripcion, int categoriaId, double precio, int stock)
    : nombre(nombre), descripcion(descripcion), categoriaId(categoriaId), precio(precio), stock(stock) {}

string Producto::toString() const {
    return nombre + "," + descripcion + "," + to_string(categoriaId) + "," + to_string(precio) + "," + to_string(stock) + "\n";
}

Producto Producto::fromString(const string& data) {
    stringstream ss(data);
    string nombre, descripcion, categoriaIdStr, precioStr, stockStr;

    getline(ss, nombre, ',');
    getline(ss, descripcion, ',');
    getline(ss, categoriaIdStr, ',');
    getline(ss, precioStr, ',');
    getline(ss, stockStr, ',');

    int categoriaId = stoi(categoriaIdStr);
    double precio = stod(precioStr);
    int stock = stoi(stockStr);

    return Producto(nombre, descripcion, categoriaId, precio, stock);
}

void agregarProducto() {
    string nombre, descripcion;
    int categoriaId;
    double precio;
    int stock;

    cout << "Ingrese nombre del producto: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese descripcion del producto: ";
    getline(cin, descripcion);

    // Consultar categorías
    listarCategorias();
    cout << "Seleccione ID de la categoria: ";
    cin >> categoriaId;

    cout << "Ingrese precio del producto: ";
    cin >> precio;
    cout << "Ingrese stock inicial: ";
    cin >> stock;

    Producto nuevoProducto(nombre, descripcion, categoriaId, precio, stock);

    ofstream file("inventario.txt", ios::app);
    if (file.is_open()) {
        file << nuevoProducto.toString();
        file.close();
        cout << "Producto agregado exitosamente.\n";
    } else {
        cerr << "Error al abrir el archivo.\n";
    }
}

void agregarCategoria() {
    string nombre;
    cout << "Ingrese el nombre de la nueva categoria: ";
    cin.ignore();
    getline(cin, nombre);

    // Crear nueva categoría y agregar al vector
    Categoria nuevaCategoria(siguienteIdCategoria++, nombre);
    categorias.push_back(nuevaCategoria);

    ofstream file("categorias.txt", ios::app);
    if (file.is_open()) {
        file << nuevaCategoria.id << "," << nuevaCategoria.nombre << endl;
        file.close();
        cout << "Categoria agregada exitosamente.\n";
    } else {
        cerr << "Error al abrir el archivo de categorias.\n";
    }
}

void listarCategorias() {
    cout << "\n--- Categorías ---\n";
    for (const auto& categoria : categorias) {
        cout << "ID: " << categoria.id << ", Nombre: " << categoria.nombre << endl;
    }
}

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

        int id = stoi(idStr);
        categorias.push_back(Categoria(id, nombre));

        // Actualiza el siguiente ID si es necesario
        if (id >= siguienteIdCategoria) {
            siguienteIdCategoria = id + 1;
        }
    }
    file.close();
}

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
