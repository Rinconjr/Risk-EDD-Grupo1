//*****************************************************************
// Autores: Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
// Proyecto juego risk - Estructuras de datos
// Compilación: "g++ -std=c++11 risk_functions.cxx risk.cpp -o ejecutable"
// Ejecución: "./ejecutable"
// 
//
//  Archivo creado por Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
//  Fecha de inicio: 28/07/23
//  Fecha de finalización: ---
//*****************************************************************


#ifndef RISK_H
#define RISK_H


//*****************************************************************
// INICIO - LIBRERIAS INCLUIDAS
//*****************************************************************
#include <string>
#include <vector>
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************


//*****************************************************************
// INICIO - FIRMA FUNCIONES
//*****************************************************************
void comando_inicializar();
void comando_turno();
void comando_guardar();
void comando_guardar_comprimido();
void comando_costo_conquista();
void comando_conquista_mas_barata();
void comando_ayuda();
void comando_ayuda_comandos(const std::string& comando);
//*****************************************************************
// FIN - FIRMA FUNCIONES
//*****************************************************************


#endif // RISK_H

//eof - risk.h
