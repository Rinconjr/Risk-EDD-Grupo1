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

#ifndef __DADO__H__
#define __DADO__H__

//*****************************************************************
// INICIO - LIBRERIAS INCLUIDAS
//*****************************************************************
#include <string>
#include <vector>
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************


//*****************************************************************
// INICIO - CLASE DADO
//*****************************************************************

class Dado{
    private:
        std::string color;
        int valor;

    public:
        //============================
        //Constructor
        //============================
        Dado(std::string& color, int valor);

        //============================
        //Getters y Setters
        //============================
        std::string ObtenerColor() ;
        int ObtenerValor() ;
        void FijarColor(std::string& ncolor);
        void FijarValor(int nvalor);
};

//*****************************************************************
// FIN - CLASE DADO
//*****************************************************************

#include "dado.hxx"

#endif // __DADO__H__
