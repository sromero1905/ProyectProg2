#ifndef MODULOHISTORIALVENTAS_H
#define MODULOHISTORIALVENTAS_H

#include <string>  // Asegúrate de incluir esta línea para usar std::string

class ModuloHistorialVentas {
public:
    void verHistorialVentas();
    void buscarPorFecha();
    void buscarPorProducto(const std::string& producto);  // Asegúrate de que este tipo de argumento sea std::string
    void buscarPorCategoria(const std::string& categoria);  // Asegúrate de que este tipo de argumento sea std::string
    void buscarPorFechaExacta(const std::string& fecha);  // Añade la declaración de la función buscarPorFechaExacta
    void buscarPorMes(const std::string& mes);  // Añade la declaración de la función buscarPorMes
    void buscarPorAnio(const std::string& anio);  // Añade la declaración de la función buscarPorAnio
};

void mostrarMenuHistorialVentas();

#endif // MODULOHISTORIALVENTAS_H
