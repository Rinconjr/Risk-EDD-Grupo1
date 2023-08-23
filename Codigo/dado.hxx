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

Dado::Dado(){
    this->color="";
    this->valor=0;
}

Dado::Dado(std::string color, int valor) : color(color), valor(valor) {
    this->color=color;
    this->valor=valor;
}

std::string Dado::ObtenerColor(){
    return this->color;
}

int Dado::ObtenerValor(){
    return this->valor;
}

void Dado::FijarColor(std::string ncolor){
    this->color = ncolor;
}

void Dado::FijarValor(int nvalor){
    this->valor = nvalor;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - dado.hxx