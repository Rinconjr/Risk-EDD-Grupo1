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
#include "jugador.h"
#include "carta.h"
#include "dado.h"
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************

class Partida {
  private:
    std::string nombre;
    std::string tipo;
    int setsTradeados;
    std::vector<Continente> continentes;
    std::queue<Jugador> jugadores;
    std::vector<Carta> cartas;
    std::vector<Dado> dados;

  public:
    //============================
    //Constructor
    //============================
    Partida();

    //============================
    //Getters y Setters
    //============================
    std::string ObtenerNombre() const;
    std::string ObtenerTipoPartida() const;
    int ObtenersetsTradeados() const;
    std::vector<Continente> ObtenerContinentes() const;
    std::queue<Jugador> ObtenerJugadores() const;
    std::vector<Carta> ObtenerCartas() const;
    std::vector<Dado> ObtenerDados() const;

    void FijarNombre(const std::string& nnombre);
    void FijarTipoJuego(const std::string& ntipo);
    void FijarsetsTradeados(int ntradeos);
    void FijarContinentes(const std::vector<Continente>& ncontinentes);
    void FijarJugadores(const std::queue<Jugador>& njugadores);
    void FijarCartas(const std::vector<Carta>& ncartas);
    void FijarDados(const std::vector<Dado>& ndados);
};

//*****************************************************************
// FIN - CLASE PARTIDA
//*****************************************************************

#include "partida.hxx"

#endif // __PARTIDA__H__
