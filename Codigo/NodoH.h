#ifndef NODOH_H
#define NODOH_H

class NodoH {
public:
    char data;
    int frequencia;
    NodoH* izq;
    NodoH* der;

    NodoH(char data, int frequency);
};

#include "NodoH.hxx"


#endif // NodoH_H
