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
    std::string id;
    bool estado;
    std::string color;
    std::vector<std::string> paises;
    std::vector<Carta> cartas;

  public:
  
    //============================
    //Constructor
    //============================
    Jugador();

    Jugador(std::string nid, bool nbool,std::string ncolor, std::vector<std::string> npaises, std::vector<Carta> ncartas) :
        id(nid), 
        estado(nbool), 
        color(ncolor), 
        paises(npaises), 
        cartas(ncartas) 
    {}

    //============================
    //Getters y Setters
    //============================
    std::string ObtenerId();
    bool ObtenerEstado();
    std::string ObtenerColor();
    std::vector<std::string> ObtenerPaises();
    std::vector<Carta> ObtenerCartas();

    void FijarId(const std::string nid);
    void FijarEstado(bool nbool);
    void FijarColor(const std::string ncolor);
    void FijarPaises(const std::vector<std::string> npaises);
    void FijarCartas(const std::vector<Carta> ncartas);
};

//*****************************************************************
// FIN - CLASE JUGADOR
//*****************************************************************

#include "jugador.hxx"

#endif // __JUGADOR__H__
