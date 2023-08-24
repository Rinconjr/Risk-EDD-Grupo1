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

Carta::Carta(){
    this->tipo="";
    this->pais="";
    this->tropa="";
}

Carta::Carta(std::string tipo, std::string pais, std::string tropa){
    this->tipo=tipo;
    this->pais=pais;
    this->tropa=tropa;
}

std::string Carta::ObtenerTipo() {
    return this->tipo;
}

std::string Carta::ObtenerPais() {
    return this->pais;
}

std::string Carta::ObtenerTropa() {
    return this->tropa;
}

void Carta::FijarTipo(std::string ncarta) {
    this->tipo = ncarta;
}

void Carta::FijarPais(std::string ntarjeta) {
    this->pais = ntarjeta;
}

void Carta::FijarTropa(std::string ntropa) {
    this->tropa = ntropa;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - carta.hxx