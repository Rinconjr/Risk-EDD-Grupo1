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

class jugador {
  private:
    std::string id_jugador;
    bool estadoJugador;
    std::string color;
    std::vector<pais>paises;
    std::vector<carta>cartas;

  public:

    //============================
    //Constructor
    //============================
    jugador(const std::string& id, bool estado, const std::string& color, const std::vector<pais>& paises, const std::vector<carta>& cartas);

    //============================
    //Getters y Setters
    //============================

    std::string ObtenerIdJugador() const;
    bool ObtenerEstadoJugador() const;
    std::string ObtenerColor() const;
    std::vector<pais> ObtenerPaises() const;
    std::vector<carta> ObtenerCartas() const;

    void FijarIdJugador(const std::string& id);
    void FijarEstadoJugador(bool estado);
    void FijarColor(const std::string& col);
    void FijarPaises(const std::vector<pais>& p);
    void FijarCartas(const std::vector<carta>& c);
};

//*****************************************************************
// FIN - CLASE JUGADOR
//*****************************************************************

#include "jugador.hxx"

#endif // __JUGADOR__H__
