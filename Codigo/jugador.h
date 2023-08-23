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
    std::vector<Pais> paises;
    std::vector<Carta> cartas;

  public:
  
    //============================
    //Constructor
    //============================
    Jugador();

    //============================
    //Getters y Setters
    //============================
    std::string ObtenerId() const;
    bool ObtenerEstado() const;
    std::string ObtenerColor() const;
    std::vector<Pais> ObtenerPaises() const;
    std::vector<Carta> ObtenerCartas() const;

    void FijarId(const std::string& nid);
    void FijarEstado(bool nbool);
    void FijarColor(const std::string& ncolor);
    void FijarPaises(const std::vector<Pais>& npaises);
    void FijarCartas(const std::vector<Carta>& ncartas);
};

//*****************************************************************
// FIN - CLASE JUGADOR
//*****************************************************************

#include "jugador.hxx"

#endif // __JUGADOR__H__
