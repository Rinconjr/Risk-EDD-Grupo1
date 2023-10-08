#include "ArbolH.h"
#include <iostream>
#include <fstream>

ArbolH::ArbolH() {
    raiz = nullptr;
}

ArbolH::ArbolH(std::map<char, int> frequencias) {
    raiz = nullptr;
    construirArbolH(frequencias);
}

void ArbolH::construirArbolH(std::map<char, int> frequencias) {
    std::priority_queue<NodoH*, std::vector<NodoH*>, compararNodos> minHeap;

    for (auto& pair : frequencias) {
        minHeap.push(new NodoH(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        NodoH* izq = minHeap.top();
        minHeap.pop();
        NodoH* der = minHeap.top();
        minHeap.pop();

        NodoH* nodoNuevo = new NodoH('\0', izq->frequencia + der->frequencia);
        nodoNuevo->izq = izq;
        nodoNuevo->der = der;
        minHeap.push(nodoNuevo);
    }

    raiz = minHeap.top();
}

void ArbolH::construirCodigoHuffam(NodoH* nodo, std::string codigo, std::map<char, std::string>& codigosHuffman) {
    if (!nodo)
        return;

    if (!nodo->izq && !nodo->der)
        codigosHuffman[nodo->data] = codigo;

    construirCodigoHuffam(nodo->izq, codigo + "0", codigosHuffman);
    construirCodigoHuffam(nodo->der, codigo + "1", codigosHuffman);
}

std::map<char, std::string> ArbolH::obtenerCodigoHuffman() {
    std::map<char, std::string> codigosHuffman;
    construirCodigoHuffam(raiz, "", codigosHuffman);
    return codigosHuffman;
}

std::string ArbolH::codificar(std::string texto) {
    std::map<char, std::string> codigosHuffman = obtenerCodigoHuffman();
    std::string codificado;

    for (char c : texto) {
        codificado += codigosHuffman[c];
    }

    return codificado;
}

std::string ArbolH::decodificar(std::string textoCodificado) {
    std::string decodificado;
    NodoH* actual = raiz;

    for (char bit : textoCodificado) {
        if (bit == '0') {
            actual = actual->izq;
        } else if (bit == '1') {
            actual = actual->der;
        }

        if (!actual->izq && !actual->der) {
            decodificado += actual->data;
            actual = raiz;
        }
    }

    return decodificado;
}

void ArbolH::guardarEnArchivoBinario(std::string mensaje, std::string nombreArchivo, std::map<char,int> frecuencias) {
    // Abrir el archivo binario en modo de escritura binaria
    std::ofstream archivo(nombreArchivo, std::ios::binary);

    if (archivo.is_open()) {
        // Calcular la cantidad de caracteres diferentes en el mensaje
        int caracteresDiferentes = frecuencias.size();
    

        // Escribir el número de caracteres diferentes en 2 bytes (short)
        short numCaracteresDiferentes = static_cast<short>(caracteresDiferentes);
        archivo.write(reinterpret_cast<char*>(&numCaracteresDiferentes), sizeof(numCaracteresDiferentes));

        // Escribir los pares (caracter, frecuencia) en el archivo
        for (const auto& par : frecuencias) {
            unsigned char caracter = par.first;
            long long frecuencia = par.second;

            archivo.write(reinterpret_cast<char*>(&caracter), sizeof(caracter));
            archivo.write(reinterpret_cast<char*>(&frecuencia), sizeof(frecuencia));
        }

        // Escribir la longitud del archivo original en 8 bytes (long long)
        long long longitudArchivo = mensaje.size();
        archivo.write(reinterpret_cast<char*>(&longitudArchivo), sizeof(longitudArchivo));

        // Escribir la secuencia binaria (completar con '0' si es necesario)
        std::string binarioCompleto = this->codificar(mensaje);
        int bitsFaltantes = 8 - (mensaje.size() % 8);
        if (bitsFaltantes != 8) {
            binarioCompleto += std::string(bitsFaltantes, '0');
        }
        archivo.write(binarioCompleto.c_str(), binarioCompleto.size());

        // Cerrar el archivo
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
    }
}

std::string ArbolH::leerArchivoBinario(std::string nombreArchivo) {
    // Abrir el archivo binario en modo de lectura binaria
    std::ifstream archivo(nombreArchivo, std::ios::binary);

    if (archivo.is_open()) {
        // Leer la cantidad de caracteres diferentes en 2 bytes (short)
        short numCaracteresDiferentes;
        archivo.read(reinterpret_cast<char*>(&numCaracteresDiferentes), sizeof(numCaracteresDiferentes));

        // Leer los pares (caracter, frecuencia) en el archivo
        std::map<char, long long> frecuencias;
        for (int i = 0; i < numCaracteresDiferentes; ++i) {
            unsigned char caracter;
            long long frecuencia;

            archivo.read(reinterpret_cast<char*>(&caracter), sizeof(caracter));
            archivo.read(reinterpret_cast<char*>(&frecuencia), sizeof(frecuencia));
            frecuencias[caracter] = frecuencia;
        }

        // Leer la longitud del archivo original en 8 bytes (long long)
        long long longitudArchivo;
        archivo.read(reinterpret_cast<char*>(&longitudArchivo), sizeof(longitudArchivo));

        // Leer la secuencia binaria
        char buffer;
        std::string secuenciaBinaria;

        while (archivo.get(buffer)) {
            secuenciaBinaria.push_back(buffer);
        }

        // Eliminar los '0' agregados para completar los bits
        int bitsFaltantes = 8 - (longitudArchivo % 8);
        if (bitsFaltantes != 8) {
            secuenciaBinaria.erase(secuenciaBinaria.end() - bitsFaltantes, secuenciaBinaria.end());
        }

        // Decodificar la secuencia binaria
        std::map<char, int> frec;
        for (const auto& par : frecuencias) {
            unsigned char caracter = par.first;
            int fr = par.second;

            frec[caracter] = fr;
        }

        construirArbolH(frec);
        

        std::string mensaje = this->decodificar(secuenciaBinaria);
        // Cerrar el archivo
        archivo.close();

        return mensaje;

    } else {
        std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
        return "";
    }
}
