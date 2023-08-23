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
#include "tropa.h"
#include <iostream>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************

Pais::Pais(){}

std::string Pais::ObtenerNombre() const{
    return nombre;
}

std::vector<Tropa> Pais::ObtenerTropas() const{
    return tropas;
}

int Pais::ObtenerCantidadTropas() const {
    return cantidadTropas;
}

std::vector<Pais> Pais::ObtenerPaisesVecinos() const {
    return paisesVecinos;
}

std::string Pais::ObtenerColor() const {
    return color;
}

void Pais::FijarNombre(const std::string& nnombre){
    nombre = nnombre;
}

void Pais::FijarTropas(const std::vector<Tropa>& ntropas) {
    tropas = ntropas;
}

void Pais::FijarCantidadTropas(int ncantidadtropas) {
    cantidadTropas = ncantidadtropas;
}

void Pais::FijarPaisesVecinos(const std::vector<Pais>& npaisesvecinos) {
    paisesVecinos = npaisesvecinos;
}

void Pais::FijarColor(const std::string& ncolor) {
    color = ncolor;
}



//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - pais.hxx