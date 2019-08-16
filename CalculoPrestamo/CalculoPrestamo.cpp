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

#include <cstdint>
#include <string>
#include <iostream>
#include "CalculoPrestamo.h"

void CalculoPrestamo::setMonto(float monto) {
        this->monto = monto;
    }

float CalculoPrestamo::getMonto(){
        return monto;
    }

CalculoPrestamo::CalculoPrestamo(){
    monto = 0.0;
}
CalculoPrestamo::CalculoPrestamo(int64_t monto){
   this->monto = monto;
}
float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT){
    float percent= 0;
    int buscarpor = porcentajeTXT.find("%");
    if(buscarpor > 0){
       percent=std::stof(porcentajeTXT.substr(0, buscarpor)); 
       if(percent > 0){
          percent = percent / 100;
       }
    }
    return percent;
}
int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT){
    int mes = 0;
    int anno = 0;
    int busTA = tiempoTXT.find("A");
    int busTM = tiempoTXT.find("M");
       if(busTA > 0){
        anno = stoi(tiempoTXT.substr(0, busTA));
        if(anno > 0){
            mes = anno *12;
        }
    } else if(busTM > 0){
        mes = stoi(tiempoTXT.substr(0, busTM));
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
        tasa = tasa +"Tasa ("+ porcentajeTXT + "), Mes ("+std::to_string(i+1)+"), balance inicial ("+std::to_string(balance1)+"), interes ("+std::to_string(interes)+"), balance nuevo ("+std::to_string(balance2)+")\n";
        balance1 = balance2;
    }
    return tasa;
}

