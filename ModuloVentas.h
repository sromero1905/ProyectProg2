#ifndef MODULO_VENTAS_H
#define MODULO_VENTAS_H

#include <vector>
#include <string>
#include "ModuloInventario.h"  // Incluimos para utilizar Producto y Categoria
#include "ModuloReportes.h"    // Incluimos para utilizar la clase Venta

using namespace std;

// Estructura para representar un item de venta (producto con cantidad)
struct ItemVenta {
    Producto producto;
    int cantidad;
};

// Clase para gestionar las ventas
class ModuloVentas {
private:
    vector<ItemVenta> itemsVenta;       // Lista de items en la venta actual
    double subtotal = 0;                // Subtotal de la venta
    double total = 0;                   // Total de la venta

    vector<Categoria> cargarCategoriasVentas(); // Carga categorías desde archivo
    void listarCategorias();                    // Muestra las categorías cargadas
    void listarProductosPorCategoria(int categoriaId); // Lista productos por categoría
    void guardarVentaEnArchivo(const Venta& venta);    // Guarda la venta en archivo

public:
    void mostrarMenuVentas();            // Muestra el menú de ventas
    void registrarVenta();               // Registra una venta de productos
    void finalizarVenta();               // Finaliza y guarda la venta
    void cancelarVenta();                // Cancela la venta actual
    string obtenerFechaActual();         // Obtiene la fecha actual
};

#endif // MODULO_VENTAS_H
