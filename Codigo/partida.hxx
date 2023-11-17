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
    Partida::Partida() {
        this->nombre = "";
        this->tipo = "";
        this->setsTradeados = 0;
        this->continentes = std::vector<Continente>();
        this->jugadores = std::queue<Jugador>();
        this->cartas = std::vector<Carta>();
    }

    Partida::Partida(std::string nnombre,std::string ntipo, int ntradeos, std::vector<Continente> ncontinentes, std::queue<Jugador> njugadores, std::vector<Carta> ncartas) {
        this->nombre = nnombre;
        this->tipo = ntipo;
        this->setsTradeados = ntradeos;
        this->continentes = ncontinentes;
        this->jugadores = njugadores;
        this->cartas = ncartas;
    }

    std::string Partida::ObtenerNombre() {
        return this->nombre;
    }
    std::string Partida::ObtenerTipoPartida() {
        return this->tipo;
    }
    int Partida::ObtenersetsTradeados() {
        return this->setsTradeados;
    }
    std::vector<Continente> Partida::ObtenerContinentes() {
        return this->continentes;
    }
    std::queue<Jugador> Partida::ObtenerJugadores() {
        return this->jugadores;
    }
    std::vector<Carta> Partida::ObtenerCartas() {
        return this->cartas;
    }

    void Partida::FijarNombre(std::string nnombre) {
        this->nombre = nnombre;
    }
    void Partida::FijarTipoJuego(std::string ntipo) {
        this->tipo = ntipo;
    }
    void Partida::FijarsetsTradeados(int ntradeos) {
        this->setsTradeados = ntradeos;
    }
    void Partida::FijarContinentes(std::vector<Continente> ncontinentes) {
        this->continentes = ncontinentes;
    }
    void Partida::FijarJugadores(std::queue<Jugador> njugadores) {
        this->jugadores = njugadores;
    }
    void Partida::FijarCartas(std::vector<Carta> ncartas) {
        this->cartas = ncartas;
    }

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - partida.hxx