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
CalculoPrestamo::CalculoPrestamo(int monto){
   this->monto = monto;
}
float CalculoPrestamo::obtenerPorcentaje(string porcentajeTXT){
    int pos = porcentajeTXT.find("%");
    string aux = porcentajeTXT.substr(0, pos);
    return (stof(aux) / 100);
}
int CalculoPrestamo::calcularTiempoEnMeses(string tiempoTXT){
    string auxString;
    int pos;
    if (tiempoTXT.find("A") != -1) {
        pos = tiempoTXT.find("A");
        auxString = tiempoTXT.substr(0, pos);
        return ((stoi(auxString))*12);
    } else {
        pos = tiempoTXT.find("M");
        auxString = tiempoTXT.substr(0, pos);
        return (stoi(auxString));
    }
}
float CalculoPrestamo::calcularInteresMensual(float balance,float tasaAnual){
    return (balance * (tasaAnual / 12));
}
string CalculoPrestamo::reporteCalculoPrestamo(string tiempoTXT,string porcentajeTXT){
    int balance1 = getMonto();
    float interes = calcularInteresMensual(balance1,obtenerPorcentaje(porcentajeTXT));
    int balance2 = balance1 + interes;
    int meses = calcularTiempoEnMeses(tiempoTXT);
    std::string tasa;

    for (int i=0; i <= meses; i++) {
        tasa = "Tasa (" + porcentajeTXT + "), Mes (" + i + "), balance inicial (" + balance1 + "), interes (" + interes + "), balance nuevo (" + balance2 + ")\n";
        return tasa;
        balance1 = balance2;
    }
}


