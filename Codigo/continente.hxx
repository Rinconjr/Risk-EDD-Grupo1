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
#include "continente.h"
#include "pais.h"
#include <iostream>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************

Continente::Continente(){}

std::string Continente::ObtenerNombre() const {
    return nombre;
}

std::vector<Pais> Continente::ObtenerPaises() const {
    return paises;
}

std::string Continente::ObtenerColor() const {
    return color;
}

void Continente::FijarNombre(const std::string& nnombre) {
    nombre = nnombre;
}

void Continente::FijarPaises(const std::vector<Pais>& npaises) {
    paises = npaises;
}

void Continente::FijarColor(const std::string& ncolor) {
    color = ncolor;
}


//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - continente.hxx