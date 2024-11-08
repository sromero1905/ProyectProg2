#ifndef REGISTROVENTAS_H
#define REGISTROVENTAS_H

#include <vector>
#include "Utilidades.h"

// Función para registrar venta
void registrarVenta(std::vector<Producto> &productos);

// Actualizar inventario después de una venta
void actualizarInventario(const Producto &producto, int cantidadVendida);

#endif // REGISTROVENTAS_H
