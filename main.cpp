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

#include <iostream>
#include "CalculoPrestamo.h"

int main() {
    
    CalculoPrestamo ejm1(30000);
    std::cout<<ejm1.calcularInteresMensual(ejm1.getMonto(),ejm1.obtenerPorcentaje("8.40"))<<"\n";
    std::cout<<ejm1.calcularTiempoEnMeses("3A")<<"\n";
    std::cout<<ejm1.reporteCalculoPrestamo("3A","8.40")<<"\n";
    
    
    return 0;
}