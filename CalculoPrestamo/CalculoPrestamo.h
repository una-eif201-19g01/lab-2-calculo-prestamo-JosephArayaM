/*
 * =====================================================================================
 *
 *       File Name:  CalculoPrestamo.h
 *
 *    Description:  Laboratorio 2
 *
 *        Created:  14/08/2019
 *
 *         Author:  Joseph Araya Moore
 *
 * =====================================================================================
 */

#ifndef CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_H

#include <cstdint>
#include <string>

class CalculoPrestamo{
private:
    float monto;
public:
    CalculoPrestamo();
    CalculoPrestamo(int64_t monto);
    float obtenerPorcentaje(std::string porcentajeTXT);
    int calcularTiempoEnMeses(std::string tiempoTXT);
    float calcularInteresMensual(float balance,float tasaAnual);
    std::string reporteCalculoPrestamo(std::string tiempoTXT,std::string porcentajeTXT);
    void setMonto(float monto);
    float getMonto();
};


#endif /* CALCULOPRESTAMO_H */

