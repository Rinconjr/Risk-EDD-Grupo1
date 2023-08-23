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

Carta::Carta(std::string tipo,std::string pais, std::string tropa):tipo(tipo),pais(pais),tropa(tropa){
    this->tipo=tipo;
    this->pais=pais;
    this->tropa=tropa;
}

std::string Carta::ObtenerTipo() const {
    return this-> tipo;
}

std::string Carta::ObtenerPais() const {
    return this->pais;
}

std::string Carta::ObtenerTropa() const {
    return this->tropa;
}

void Carta::FijarTipo(const std::string ncarta) {
    this->tipo = ncarta;
}

void Carta::FijarPais(const std::string ntarjeta) {
    this->pais = ntarjeta;
}

void Carta::FijarTropa(const std::string ntropa) {
    this->tropa = ntropa;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - carta.hxx