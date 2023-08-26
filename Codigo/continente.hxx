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
    this->tropasAdicionales = 0;
    this->paises = std::vector<Pais>();
    this->bonificacion = 0;
}

Continente::Continente(std::string nombre, std::vector<Pais> paises, int nTropasAdicionales, int nbonificacion){
    this->nombre = nombre;
    this->tropasAdicionales = nTropasAdicionales;
    this->paises = paises;
    this->bonificacion = nbonificacion;
}

std::string Continente::ObtenerNombre() {
    return this->nombre;
}

int Continente::ObtenerTropasAdicionales() {
    return this->tropasAdicionales;
}

std::vector<Pais> Continente::ObtenerPaises() {
    return paises;
}

int Continente::ObtenerBonificacion() {
    return this->bonificacion;
}

void Continente::FijarNombre(std::string nnombre) {
    this->nombre = nnombre;
}

void Continente::FijarTropasAdicionales(int nTropasAdicionales) {
    this->tropasAdicionales = nTropasAdicionales;
}

void Continente::FijarPaises(std::vector<Pais> npaises) {
    this->paises = npaises;
}

void Continente::FijarBonificacion(int nbonificacion) {
    this->bonificacion = nbonificacion;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - continente.hxx
