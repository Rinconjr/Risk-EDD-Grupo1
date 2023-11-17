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

  public:
    //============================
    //Constructor
    //============================
    Partida();

    Partida(std::string nnombre,std::string ntipo, int ntradeos, std::vector<Continente> ncontinentes, std::queue<Jugador> njugadores, std::vector<Carta> ncartas);

    //============================
    //Getters y Setters
    //============================
    std::string ObtenerNombre();
    std::string ObtenerTipoPartida();
    int ObtenersetsTradeados();
    std::vector<Continente> ObtenerContinentes();
    std::queue<Jugador> ObtenerJugadores();
    std::vector<Carta> ObtenerCartas();

    void FijarNombre(std::string nnombre);
    void FijarTipoJuego(std::string ntipo);
    void FijarsetsTradeados(int ntradeos);
    void FijarContinentes(std::vector<Continente> ncontinentes);
    void FijarJugadores(std::queue<Jugador> njugadores);
    void FijarCartas(std::vector<Carta> ncartas);

};

//*****************************************************************
// FIN - CLASE PARTIDA
//*****************************************************************

#include "partida.hxx"

#endif // __PARTIDA__H__
