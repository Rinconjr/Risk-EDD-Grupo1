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
    private:
        std::string tipo;
        std::string pais;
        std::string tropa;

    public:
        //============================
        //Constructor
        //============================
        Carta::Carta(std::string& ncarta,std::string& ntarjeta, std::string& ntropa);
        
        //============================
        //Getters y Setters
        //============================
        std::string ObtenerTipo();
        std::string ObtenerPais();
        std::string ObtenerTropa();

        void FijarTipo(std::string& ncarta);
        void FijarPais(std::string& ntarjeta);
        void FijarTropa(std::string& ntropa);
};

//*****************************************************************
// FIN - CLASE CARTA
//*****************************************************************

#include "carta.hxx"

#endif // __CARTA__H__