//*****************************************************************
// Autores: Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
// Proyecto juego risk - Estructuras de datos
// Compilación: "g++ -std=c++11 main.cpp -o risk"
// Ejecución: "./risk"
// 
//
//  Archivo creado por Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
//  Fecha de inicio: 28/07/23
//  Fecha de finalización: ----
//*****************************************************************

//************************************************************************
// INICIO - LIBRERIAS
//************************************************************************
#include "carta.h"
#include <iostream>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************

//************************************************************************
// INICIO - FUNCIONES
//************************************************************************

Carta::Carta() : tipo(""), pais(""), tropa("") {}

std::string Carta::ObtenerTipo() const {
    return tipo;
}

std::string Carta::ObtenerPais() const {
    return pais;
}

std::string Carta::ObtenerTropa() const {
    return tropa;
}

void Carta::FijarTipo(const std::string& ncarta) {
    tipo = ncarta;
}

void Carta::FijarPais(const std::string& ntarjeta) {
    pais = ntarjeta;
}

void Carta::FijarTropa(const std::string& ntropa) {
    tropa = ntropa;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - carta.hxx