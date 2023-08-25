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

#ifndef __PAIS__H__
#define __PAIS__H__

//*****************************************************************
// INICIO - LIBRERIAS INCLUIDAS
//*****************************************************************
#include <string>
#include <vector>
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************


//*****************************************************************
// INICIO - CLASE PAIS
//*****************************************************************

class Pais{
    private:
        std::string nombre;
        int cantidadTropas;
        int dueno;

    public:
        //============================
        //Constructor
        //============================
        Pais();

        Pais(std::string nombre, int cantidadTropas);

        //============================
        //Getters y Setters
        //============================
        std::string ObtenerNombre();
        int ObtenerCantidadTropas();
        int ObtenerDueno();

        void FijarNombre(std::string nnombre);
        void FijarCantidadTropas(int ncantidadtropas);
        void FijarDueno(int ndueno);
};

//*****************************************************************
// FIN - CLASE PAIS
//*****************************************************************

#include "pais.hxx"

#endif // __PAIS__H__
