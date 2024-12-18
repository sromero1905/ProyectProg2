#ifndef MODULO_INVENTARIO_H
#define MODULO_INVENTARIO_H

#include <vector>
#include <string>

// Clase para representar una categorķa
class Categoria {
public:
    int id;
    std::string nombre;

    Categoria(int id, std::string nombre) : id(id), nombre(nombre) {}
};

// Clase para representar un producto
class Producto {
public:
    std::string nombre;
    int categoriaId; // ID de la categorķa
    double precio;
    int stock;

    Producto(std::string nombre, int categoriaId, double precio, int stock);
    std::string toString() const;
    static Producto fromString(const std::string& data);
};

// Funciones para gestionar inventario y categorķas
void gestionarInventario();
void cargarCategorias();
void agregarProducto();
void agregarCategoria();
void consultarStock();
void listarCategorias();

#endif // MODULO_INVENTARIO_H


