#ifndef _GRAFO_H__
#define _GRAFO_H__

#include <vector>

class Grafo{
    private:
        std::vector<std::vector<int>> matriz_adyacencia;
    public:
        Grafo();
        std::vector<std::vector<int>> obtenerMatriz();
};

#include "grafo.hxx"

#endif