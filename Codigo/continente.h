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

#ifndef __CONTINENTE__H__
#define __CONTINENTE__H__

//*****************************************************************
// INICIO - LIBRERIAS INCLUIDAS
//*****************************************************************
#include <string>
#include <vector>
#include "pais.h"
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************


//*****************************************************************
// INICIO - CLASE CONTINENTE
//*****************************************************************

class Continente{
    private:
        std::string nombre;
        std::string color;
        std::vector<Pais> paises;
        
    public:
        //============================
        //Constructor
        //============================
        Continente();

        //============================
        //Getters y Setters
        //============================
        std::string ObtenerNombre() const;
        std::string ObtenerColor() const;
        std::vector<Pais> ObtenerPaises() const;

        void FijarNombre(const std::string& nnombre);
        void FijarColor(const std::string& ncolor);
        void FijarPaises(const std::vector<Pais>& npaises);

};

//*****************************************************************
// FIN - CLASE CONTINENTE
//*****************************************************************

#include "continente.hxx"

#endif // __CONTINENTE__H__
