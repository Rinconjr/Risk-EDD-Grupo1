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

#ifndef __JUGADOR__H__
#define __JUGADOR__H__

//*****************************************************************
// INICIO - LIBRERIAS INCLUIDAS
//*****************************************************************
#include <string>
#include <vector>
#include "pais.h"
#include "carta.h"
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************
class Jugador {
  private:
    int id;
    bool estado;
    std::string color;
    std::vector<Carta> cartas;

  public:
  
    //============================
    //Constructor
    //============================
    Jugador();

    Jugador(int nid, bool nbool,std::string ncolor, std::vector<Carta> ncartas);

    //============================
    //Getters y Setters
    //============================
    int ObtenerId();
    bool ObtenerEstado();
    std::string ObtenerColor();
    std::vector<Carta> ObtenerCartas();

    void FijarId(int nid);
    void FijarEstado(bool nbool);
    void FijarColor(std::string ncolor);
    void FijarCartas(std::vector<Carta> ncartas);
};

//*****************************************************************
// FIN - CLASE JUGADOR
//*****************************************************************

#include "jugador.hxx"

#endif // __JUGADOR__H__
