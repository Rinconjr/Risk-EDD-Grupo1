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
#include "tropa.h"
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************


//*****************************************************************
// INICIO - CLASE PAIS
//*****************************************************************

class Pais{
    public:
        Pais();

        std::string ObtenerNombre() const;
        std::vector<Tropa> ObtenerTropas() const;
        int ObtenerCantidadTropas() const;
        std::vector<Pais> ObtenerPaisesVecinos() const;
        std::string ObtenerColor() const;

        void FijarNombre(const std::string& nnombre);
        void FijarTropas(const std::vector<Tropa>& ntropas);
        void FijarCantidadTropas(int ncantidadtropas);
        void FijarPaisesVecinos(const std::vector<Pais>& npaisesvecinos);
        void FijarColor(const std::string& ncolor);

    private:
        std::string nombre;
        std::vector<Tropa> tropas;
        int cantidadTropas;
        std::vector<Pais> paisesVecinos;
        std::string color;

};

//*****************************************************************
// FIN - CLASE PAIS
//*****************************************************************

#include "pais.hxx"

#endif // __PAIS__H__
