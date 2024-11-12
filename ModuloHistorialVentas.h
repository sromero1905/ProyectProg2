#ifndef MODULOHISTORIALVENTAS_H
#define MODULOHISTORIALVENTAS_H

#include <string>

class ModuloHistorialVentas {
public:
    void verHistorialVentas();
    void buscarPorFecha();
    void buscarPorProducto(const std::string& producto);
    void buscarPorCategoria(const std::string& categoria);
    void buscarPorFechaExacta(const std::string& fecha);
    void buscarPorMes(const std::string& mes);
    void buscarPorAnio(const std::string& anio);

};

void mostrarMenuHistorialVentas();

#endif // MODULOHISTORIALVENTAS_H
