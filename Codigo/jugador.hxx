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

    jugador::jugador(const std::string& id, bool estado, const std::string& color, const std::vector<pais>& paises, const std::vector<carta>& cartas): 
      id_jugador(id), 
      estadoJugador(estado), 
      color(color), 
      paises(paises), 
      cartas(cartas) 
    {}
    
    std::string  jugador::ObtenerIdJugador() const {
        return id_jugador;
    }
    bool ObtenerEstadoJugador() const {
        return estadoJugador;
    }
    std::string jugador::ObtenerColor() const {
        return color;
    }
    td::vector<pais> jugador::ObtenerPaises() const {
        return paises;
    }
    std::vector<carta> jugador::ObtenerCartas() const {
        return cartas;
    }

    void jugador::FijarIdJugador(const std::string& id) {
        id_jugador = id;
    }
    void jugador::FijarEstadoJugador(bool estado) {
        estadoJugador = estado;
    }
    void jugador::FijarColor(const std::string& col) {
        color = col;
    }
    void jugador::FijarPaises(const std::vector<pais>& p) {
        paises = p;
    }
    void jugador::FijarCartas(const std::vector<carta>& c) {
        cartas = c;
    }

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - jugador.hxx