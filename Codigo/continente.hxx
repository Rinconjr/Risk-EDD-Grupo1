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

Continente::Continente(){
    this->nombre = "";
    this->paises = std::vector<Pais>();
}

Continente::Continente(std::string nombre, std::vector<Pais> paises){
    this->nombre = nombre;
    this->paises = paises;
}

std::string Continente::ObtenerNombre() {
    return this->nombre;
}

std::vector<Pais> Continente::ObtenerPaises() {
    return paises;
}


void Continente::FijarNombre(std::string nnombre) {
    this->nombre = nnombre;
}

void Continente::FijarPaises(std::vector<Pais> npaises) {
    this->paises = npaises;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - continente.hxx