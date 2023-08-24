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
Jugador::Jugador() {
    this->id = "";
    this->estado = false;
    this->color = "";
    this->paises = std::vector<std::string>();
    this->cartas = std::vector<Carta>();
}

Jugador::Jugador(std::string nid, bool nbool,std::string ncolor, std::vector<std::string> npaises, std::vector<Carta> ncartas){
    this->id = nid;
    this->estado = nbool;
    this->color = ncolor;
    this->paises = npaises;
    this->cartas = ncartas;
}

std::string Jugador::ObtenerId() {
    return this->id;
}

bool Jugador::ObtenerEstado() {
    return this->estado;
}

std::string Jugador::ObtenerColor() {
    return this->color;
}

std::vector<std::string> Jugador::ObtenerPaises() {
    return this->paises;
}

std::vector<Carta> Jugador::ObtenerCartas() {
    return this->cartas;
}

void Jugador::FijarId(const std::string nid) {
    this->id = nid;
}

void Jugador::FijarEstado(bool nbool) {
    this->estado = nbool;
}

void Jugador::FijarColor(const std::string ncolor) {
    this->color = ncolor;
}

void Jugador::FijarPaises(const std::vector<std::string> npaises) {
    this->paises = npaises;
}

void Jugador::FijarCartas(const std::vector<Carta> ncartas) {
    this->cartas = ncartas;
}

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - jugador.hxx