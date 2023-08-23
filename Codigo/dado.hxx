//*****************************************************************
// Autores: Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
// Proyecto juego risk - Estructuras de datos
// Compilación: "g++ -std=c++11 main.cpp -o risk"
// Ejecución: "./risk"
// 
//
//  Archivo creado por Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
//  Fecha de inicio: 28/07/23
//  Fecha de finalización: ---
//*****************************************************************


//************************************************************************
// INICIO - LIBRERIAS
//************************************************************************
#include "dado.h"
#include <iostream>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************

Dado::Dado() : color("negro"), valor(0) {}

Dado::Dado(const std::string& color, int valor) : color(color), valor(valor) {}

std::string Dado::ObtenerColor() const {
    return color;
}

int Dado::ObtenerValor() const {
    return valor;
}

void Dado::FijarColor(const std::string& ncolor){
    color = ncolor;
}

void Dado::FijarValor(const int nvalor){
    valor = nvalor;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - menu.hxx