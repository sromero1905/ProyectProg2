#ifndef MODULO_VENTAS_H
#define MODULO_VENTAS_H

#include <vector>
#include <string>
#include "ModuloInventario.h"
#include "ModuloReportes.h"

using namespace std;

// Estructura para representar un item de venta (producto con cantidad)
struct ItemVenta {
    Producto producto;
    int cantidad;
};

// Clase para gestionar las ventas
class ModuloVentas {
private:
    vector<ItemVenta> itemsVenta;
    double subtotal = 0;
    double total = 0;

    vector<Categoria> cargarCategoriasVentas();
    void listarCategorias();
    void listarProductosPorCategoria(int categoriaId);
    void guardarVentaEnArchivo(const Venta& venta);
    void actualizarStockProducto(const std::string& nombre, int categoriaId, int cantidad);
public:
    void mostrarMenuVentas();
    void registrarVenta();
    void finalizarVenta();
    void cancelarVenta();
    string obtenerFechaActual();
};

#endif // MODULO_VENTAS_H
