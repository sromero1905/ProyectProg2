#ifndef MODULOHISTORIALVENTAS_H
#define MODULOHISTORIALVENTAS_H

#include <string>  // Aseg�rate de incluir esta l�nea para usar std::string

class ModuloHistorialVentas {
public:
    void verHistorialVentas();
    void buscarPorFecha();
    void buscarPorProducto(const std::string& producto);  // Aseg�rate de que este tipo de argumento sea std::string
    void buscarPorCategoria(const std::string& categoria);  // Aseg�rate de que este tipo de argumento sea std::string
    void buscarPorFechaExacta(const std::string& fecha);  // A�ade la declaraci�n de la funci�n buscarPorFechaExacta
    void buscarPorMes(const std::string& mes);  // A�ade la declaraci�n de la funci�n buscarPorMes
    void buscarPorAnio(const std::string& anio);  // A�ade la declaraci�n de la funci�n buscarPorAnio
};

void mostrarMenuHistorialVentas();

#endif // MODULOHISTORIALVENTAS_H
