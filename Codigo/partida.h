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

#ifndef __PARTIDA__H__
#define __PARTIDA__H__

//*****************************************************************
// INICIO - LIBRERIAS INCLUIDAS
//*****************************************************************
#include <string>
#include <vector>
#include <queue>
#include "continente.h"
#include "carta.h"
#include "dado.h"
#include "pais.h"
#include "jugador.h"
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************

class partida {
  private:
    std::string nombre;
    std::string tipoJuego;
    int FijarsTradeados;
    std::vector<continente> continentes;
    std::queue<jugador> jugadores;
    std::vector<carta>cartas;
    std::vector<dado>dados;

  public:
    //============================
    //Constructor
    //============================
    partida(std::string nombre, std::string tipoJuego, int FijarsTradeados, std::vector<continente> continentes, std::queue<jugador> jugadores, std::vector<carta>cartas,std::vector<dado>dados):
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
    std::string ObtenerNombre() const {
        return nombre;
    }
    void FijarNombre(const std::string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    std::string ObtenerTipoJuego() const {
        return tipoJuego;
    }
    void FijarTipoJuego(const std::string& nuevoTipoJuego) {
        tipoJuego = nuevoTipoJuego;
    }


    int ObtenerFijarsTradeados() const {
        return FijarsTradeados;
    }
    void FijarFijarsTradeados(int nuevosFijarsTradeados) {
        FijarsTradeados = nuevosFijarsTradeados;
    }

    std::vector<continente> ObtenerContinentes() const {
        return continentes;
    }
    void FijarContinentes(const std::vector<continente>& nuevosContinentes) {
        continentes = nuevosContinentes;
    }

    std::queue<jugador> ObtenerJugadores() const {
        return jugadores;
    }
    void FijarJugadores(const std::queue<jugador>& nuevosJugadores) {
        jugadores = nuevosJugadores;
    }

    std::vector<carta> ObtenerCartas() const {
        return cartas;
    }
    void FijarCartas(const std::vector<carta>& nuevasCartas) {
        cartas = nuevasCartas;
    }

    std::vector<dado> ObtenerDados() const {
        return dados;
    }
    void FijarDados(const std::vector<dado>& nuevosDados) {
        dados = nuevosDados;
    }

    //============================
    //Funciones
    //============================
};

//*****************************************************************
// FIN - CLASE PARTIDA
//*****************************************************************

#include "partida.hxx"

#endif // __PARTIDA__H__
