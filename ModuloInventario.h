<<<<<<< Updated upstream
#ifndef MODULOINVENTARIO_H_INCLUDED
#define MODULOINVENTARIO_H_INCLUDED



#endif // MODULOINVENTARIO_H_INCLUDED
=======
#ifndef MODULO_INVENTARIO_H
#define MODULO_INVENTARIO_H

#include <string>
#include <vector>

using namespace std;

// Clase Categoria
class Categoria {
public:
    int id;
    string nombre;

    // Constructor de Categoria
    Categoria(int id, string nombre);
};

// Clase Producto
class Producto {
public:
    string nombre;
    string descripcion;
    int categoriaId;
    double precio;
    int stock;

    // Constructor de Producto
    Producto(string nombre, string descripcion, int categoriaId, double precio, int stock);

    // Métodos para convertir Producto a string y viceversa
    string toString() const;
    static Producto fromString(const string& data);
};

// Funciones para gestionar el inventario
void agregarProducto();
void agregarCategoria();
void listarCategorias();
void cargarCategorias();
void consultarStock();
void gestionarInventario();

#endif // MODULO_INVENTARIO_H

>>>>>>> Stashed changes
