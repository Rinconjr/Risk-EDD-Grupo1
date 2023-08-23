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
#include "carta.h"
#include "jugador.h"
#include <iostream>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************
Jugador::Jugador(){}

std::string Jugador::ObtenerId() const {
    return id;
}

bool Jugador::ObtenerEstado() const {
    return estado;
}

std::string Jugador::ObtenerColor() const {
    return color;
}

std::vector<Pais> Jugador::ObtenerPaises() const {
    return paises;
}

std::vector<Carta> Jugador::ObtenerCartas() const {
    return cartas;
}

void Jugador::FijarId(const std::string& nid) {
    id = nid;
}

void Jugador::FijarEstado(bool nbool) {
    estado = nbool;
}

void Jugador::FijarColor(const std::string& ncolor) {
    color = ncolor;
}

void Jugador::FijarPaises(const std::vector<Pais>& npaises) {
    paises = npaises;
}

void Jugador::FijarCartas(const std::vector<Carta>& ncartas) {
    cartas = ncartas;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - jugador.hxx