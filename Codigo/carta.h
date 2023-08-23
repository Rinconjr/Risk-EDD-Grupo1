//*****************************************************************
// Autores: Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
// Proyecto juego risk - Estructuras de datos
// Compilación: "g++ -std=c++11 main.cpp -o risk"
// Ejecución: "./risk"
// 
//
//  Archivo creado por Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
//  Fecha de inicio: 28/07/23
//  Fecha de finalización: ----
//*****************************************************************

#ifndef __CARTA__H__
#define __CARTA__H__

//*****************************************************************
// INICIO - LIBRERIAS INCLUIDAS
//*****************************************************************
#include <string>
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************

class Carta {
public:
    Carta(const std::string& tipo, const std::string& pais, const std::string& tropa);
    std::string ObtenerTipo() const;
    std::string ObtenerPais() const;
    std::string ObtenerTropa() const;
    void FijarTipo(const std::string& ncarta);
    void FijarPais(const std::string& ntarjeta);
    void FijarTropa(const std::string& ntropa);

private:
    std::string tipo;
    std::string pais;
    std::string tropa;
};

//*****************************************************************
// FIN - CLASE CARTA
//*****************************************************************

#include "carta.hxx"

#endif // __CARTA__H__