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
#include "pais.h"
#include <iostream>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************

Pais::Pais(){
    this->nombre="";
    this->cantidadTropas= 1 ;
}

Pais::Pais(std::string nombre, int cantidadTropas){
    this->nombre = nombre;
    this->cantidadTropas = cantidadTropas;
}

std::string Pais::ObtenerNombre(){
    return this->nombre;
}

int Pais::ObtenerCantidadTropas(){
    return this->cantidadTropas;
}

int Pais::ObtenerDueno(){
    return this->dueno;
}

void Pais::FijarNombre(std::string nnombre){
    this->nombre = nnombre;
}

void Pais::FijarCantidadTropas(int ncantidadtropas) {
    this->cantidadTropas = ncantidadtropas;
}

void Pais::FijarDueno(int ndueno) {
    this->dueno = ndueno;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - pais.hxx