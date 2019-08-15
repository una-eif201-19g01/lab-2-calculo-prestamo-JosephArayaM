/*
 * =====================================================================================
 *
 *       Filename:  CalculoPrestamo.cpp
 *
 *    Description:  Laboratorio 2
 *
 *        Created:  14/08/2019
 *
 *         Author:  Joseph Araya Moore
 *
 * =====================================================================================
 */


#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <string>
#include <sstream>

using namespace std;

class CalculoPrestamo{
private:
    float monto;
public:
    CalculoPrestamo();
    CalculoPrestamo(int monto);
    float obtenerPorcentaje(string porcentajeTXT);
    int calcularTiempoEnMeses(string tiempoTXT);
    float calcularInteresMensual(float balance,float tasaAnual);
    string reporteCalculoPrestamo(string tiempoTXT,string porcentajeTXT);
    void setMonto(float monto);
    float getMonto();
};

#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
