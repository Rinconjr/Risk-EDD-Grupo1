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
#include <string>
#include <vector>
#include <queue>
#include "continente.h"
#include "carta.h"
#include "dado.h"
#include "pais.h"
#include "jugador.h"
#include "partida.h"
#include <iostream>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************

    Partida::Partida() : nombre(""), tipo(""), setsTradeados(0) {}

    std::string Partida::ObtenerNombre() const {
        return nombre;
    }
    std::string Partida::ObtenerTipoPartida() const {
        return tipo;
    }
    int Partida::ObtenersetsTradeados() const {
        return setsTradeados;
    }
    std::vector<Continente> Partida::ObtenerContinentes() const {
        return continentes;
    }
    std::queue<Jugador> Partida::ObtenerJugadores() const {
        return jugadores;
    }
    std::vector<Carta> Partida::ObtenerCartas() const {
        return cartas;
    }
    std::vector<Dado> Partida::ObtenerDados() const {
        return dados;
    }

    void Partida::FijarNombre(const std::string& nnombre) {
        nombre = nnombre;
    }
    void Partida::FijarTipoJuego(const std::string& ntipo) {
        tipo = ntipo;
    }
    void Partida::FijarsetsTradeados(int ntradeos) {
        setsTradeados = ntradeos;
    }
    void Partida::FijarContinentes(const std::vector<Continente>& ncontinentes) {
        continentes = ncontinentes;
    }
    void Partida::FijarJugadores(const std::queue<Jugador>& njugadores) {
        jugadores = njugadores;
    }
    void Partida::FijarCartas(const std::vector<Carta>& ncartas) {
        cartas = ncartas;
    }
    void Partida::FijarDados(const std::vector<Dado>& ndados) {
        dados = ndados;
    }

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - partida.hxx