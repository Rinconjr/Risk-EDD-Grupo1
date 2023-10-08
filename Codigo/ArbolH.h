#ifndef ARBOLH_H
#define ARBOLH_H

#include <iostream>

#include "NodoH.h"

struct compararNodos {
    bool operator()(NodoH* a, NodoH* b) {
        return a->frequencia > b->frequencia;
    }
};

class ArbolH {
private:
    NodoH* raiz;

public:
    ArbolH();
    ArbolH(std::map<char, int> frequencias);

    void construirArbolH(std::map<char, int> frequencias);

    void construirCodigoHuffam(NodoH* nodo, std::string codigo, std::map<char, std::string>& codigosHuffman);

    std::map<char, std::string> obtenerCodigoHuffman();

    std::string codificar(std::string texto);

    std::string decodificar(std::string textoCodificado);

    void guardarEnArchivoBinario(std::string texto, std::string nombreArchivo, std::map<char, int> frequencias);

    std::string leerArchivoBinario(std::string nombreArchivo);
};

#include "ArbolH.hxx"

#endif //  ARBOLH_H
