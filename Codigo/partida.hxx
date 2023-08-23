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
#include <iostream>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************

     partida::partida(std::string nombre, std::string tipoJuego, int FijarsTradeados, std::vector<continente> continentes, std::queue<jugador> jugadores, std::vector<carta>cartas,std::vector<dado>dados):
      nombre(nombre),
      tipoJuego(tipoJuego),
      FijarsTradeados(FijarsTradeados),
      continentes(continentes),
      jugadores(jugadores),
      cartas(cartas),
      dados(dados)
    {}

    //============================
    //Getters y Setters
    //============================
    std::string partida::ObtenerNombre() const {
        return nombre;
    }
    std::string partida::ObtenerTipoJuego() const {
        return tipoJuego;
    }
    int partida::ObtenerFijarsTradeados() const {
        return FijarsTradeados;
    }
    std::vector<continente> partida::ObtenerContinentes() const {
        return continentes;
    }
    std::queue<jugador> partida::ObtenerJugadores() const {
        return jugadores;
    }
    std::vector<carta> partida::ObtenerCartas() const {
        return cartas;
    }
    std::vector<dado> partida::ObtenerDados() const {
        return dados;
    }

    void partida::FijarNombre(const std::string& nuevoNombre) {
        nombre = nuevoNombre;
    }
    void partida::FijarTipoJuego(const std::string& nuevoTipoJuego) {
        tipoJuego = nuevoTipoJuego;
    }
    void partida::FijarFijarsTradeados(int nuevosFijarsTradeados) {
        FijarsTradeados = nuevosFijarsTradeados;
    }
    void partida::FijarContinentes(const std::vector<continente>& nuevosContinentes) {
        continentes = nuevosContinentes;
    }
    void partida::FijarJugadores(const std::queue<jugador>& nuevosJugadores) {
        jugadores = nuevosJugadores;
    }
    void partida::FijarCartas(const std::vector<carta>& nuevasCartas) {
        cartas = nuevasCartas;
    }
    void partida::FijarDados(const std::vector<dado>& nuevosDados) {
        dados = nuevosDados;
    }

//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - partida.hxx