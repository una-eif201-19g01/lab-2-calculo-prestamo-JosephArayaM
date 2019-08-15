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

void CalculoPrestamo::setMonto(float monto) {
        this->monto = monto;
    }

float CalculoPrestamo::getMonto() const {
        return monto;
    }

CalculoPrestamo::CalculoPrestamo(){
    monto = 0.0;
}
CalculoPrestamo::CalculoPrestamo(int64_t monto){
   this->monto = monto;
}
float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT){
    int pos = porcentajeTXT.find("%");
    std::string aux = porcentajeTXT.substr(0, pos);
    return (stof(aux) / 100);
}
int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT){
    std::string subString;
    int pos;
    if (tiempoTXT.find("A") != -1) {
        pos = tiempoTXT.find("A");
        subString = tiempoTXT.substr(0, pos);
        return ((stoi(subString))*12);
    } else {
        pos = tiempoTXT.find("M");
        subString = tiempoTXT.substr(0, pos);
        return (stoi(subString));
    }
}
float CalculoPrestamo::calcularInteresMensual(float balance,float tasaAnual){
    return (balance * (tasaAnual / 12));
}
std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT,std::string porcentajeTXT){
    int64_t balance1 = getMonto();
    float interes = calcularInteresMensual(balance1,obtenerPorcentaje(porcentajeTXT));
    int64_t balance2 = balance1 + interes;
    int meses = calcularTiempoEnMeses(tiempoTXT);
    std::string tasa;

    for (int i=0; i <= meses; i++) {
        tasa = "Tasa (" + porcentajeTXT + "), Mes (" + i + "), balance inicial (" + balance1 + "), interes (" + interes + "), balance nuevo (" + balance2 + ")\n";
        return tasa;
        balance1 = balance2;
    }
}