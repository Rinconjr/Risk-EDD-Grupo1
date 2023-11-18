#ifndef _GRAFO_H__
#define _GRAFO_H__

#include <vector>

class Grafo{
    private:
        std::vector<std::string> paises;
        std::vector<std::vector<int>> matriz_adyacencia;
    public:
        Grafo();
        void setMatriz_Adyacencia(std::vector<std::vector<int>> m);
        std::vector<std::vector<int>> obtenerMatriz();
        void mostrarMatrizAdyacencia();
        void setPaises(std::vector<std::string> p);
        std::vector<std::string> obtenerPaises();
        void mostrarPaises();
        int obtenerPosicionPais(std::string pais);
        bool insertarArista(std::string origen, std::string destino, int costo);
        bool eliminarArista(std::string origen, std::string destino);

};

#include "grafo.hxx"

#endif