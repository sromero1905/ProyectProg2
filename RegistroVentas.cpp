#include "RegistroVentas.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>

// Función para obtener la fecha actual en formato YYYY-MM-DD
std::string obtenerFechaActual() {
    std::time_t now = std::time(0);
    std::tm *tm_now = std::localtime(&now);
    std::stringstream fecha;
    fecha << (tm_now->tm_year + 1900) << "-" << (tm_now->tm_mon + 1) << "-" << tm_now->tm_mday;
    return fecha.str();
}

// Función para aplicar promoción si el producto tiene descuento
double aplicarPromocion(const Producto &producto) {
    if (producto.enPromocion) {
        return producto.precio * (1 - producto.descuento);
    }
    return producto.precio;
}

// Función para registrar una venta
void registrarVenta(std::vector<Producto> &productos) {
    std::cout << "Productos disponibles:\n";
    for (size_t i = 0; i < productos.size(); ++i) {
        std::cout << i + 1 << ". " << alinearTexto(productos[i].nombre, 15)
                  << " - Stock: " << productos[i].cantidadDisponible
                  << " - Precio: $" << formatearDecimal(productos[i].precio, 2);
        if (productos[i].enPromocion) {
            std::cout << " (Promoción: " << productos[i].descuento * 100 << "% de descuento)";
        }
        std::cout << std::endl;
    }

    int opcionProducto;
    std::cout << "Seleccione el número del producto a vender: ";
    if (!validarEntrada(opcionProducto) || opcionProducto < 1 || opcionProducto > productos.size()) {
        std::cout << "Opción inválida." << std::endl;
        return;
    }

    Producto &productoSeleccionado = productos[opcionProducto - 1];
    int cantidadVenta;
    std::cout << "Ingrese la cantidad a vender: ";
    if (!validarEntrada(cantidadVenta) || cantidadVenta <= 0 || cantidadVenta > productoSeleccionado.cantidadDisponible) {
        std::cout << "Cantidad inválida o insuficiente." << std::endl;
        return;
    }

    // Calcular precio total aplicando promoción si corresponde
    double precioUnitarioConDescuento = aplicarPromocion(productoSeleccionado);
    double precioTotal = precioUnitarioConDescuento * cantidadVenta;
    std::string fecha = obtenerFechaActual();

    // Guardar venta en ventas.txt
    std::ofstream archivoVentas("ventas.txt", std::ios::app);
    if (archivoVentas.is_open()) {
        archivoVentas << fecha << "," << productoSeleccionado.nombre << ","
                      << cantidadVenta << "," << formatearDecimal(precioTotal, 2) << std::endl;
        archivoVentas.close();
        std::cout << "Venta registrada exitosamente." << std::endl;
    } else {
        std::cout << "Error al abrir el archivo de ventas." << std::endl;
        return;
    }

    // Actualizar inventario
    actualizarInventario(productoSeleccionado, cantidadVenta);
}

// Función para actualizar el inventario después de una venta
void actualizarInventario(const Producto &producto, int cantidadVendida) {
    std::vector<std::string> contenido;
    if (leerArchivo("inventario.txt", contenido)) {
        for (auto &linea : contenido) {
            std::istringstream ss(linea);
            std::string nombre;
            int stock;
            double precio;
            bool enPromocion;
            double descuento;
            if (ss >> nombre >> stock >> precio >> enPromocion >> descuento) {
                if (nombre == producto.nombre) {
                    stock -= cantidadVendida;
                    linea = nombre + "," + std::to_string(stock) + "," + formatearDecimal(precio, 2) + ","
                            + (enPromocion ? "1" : "0") + "," + formatearDecimal(descuento, 2);
                }
            }
        }
        escribirArchivo("inventario.txt", contenido);
    }
}
