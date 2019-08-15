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
    cout<<ejm1.calcularInteresMensual(ejm1.getMonto(),ejm1.obtenerPorcentaje("8.40"))<<endl;
    cout<<ejm1.calcularTiempoEnMeses("3A")<<endl;
    cout<<ejm1.reporteCalculoPrestamo("3A","8.40")<<endl;
    
    
    return 0;
}


