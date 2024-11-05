// ModuloInventario.h
#ifndef MODULO_INVENTARIO_H
#define MODULO_INVENTARIO_H

#include <vector>
#include <string>

// Clase para representar una categor�a
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
    std::string descripcion;
    int categoriaId; // ID de la categor�a
    double precio;
    int stock;

    Producto(std::string nombre, std::string descripcion, int categoriaId, double precio, int stock);
    std::string toString() const;
    static Producto fromString(const std::string& data);
};

// Funciones para gestionar inventario y categor�as
void gestionarInventario(); // Solo declaraci�n aqu�
void cargarCategorias();
void agregarProducto();
void agregarCategoria();
void consultarStock();
void listarCategorias();

#endif // MODULO_INVENTARIO_H
