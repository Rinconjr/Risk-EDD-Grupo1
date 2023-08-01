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


#ifndef __MENU__H__
#define __MENU__H__


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
void comando_inicializar_nueva_partida();
void comando_inicializar_existente(const std::string& comando);
void comando_turno();
void comando_guardar();
void comando_guardar_comprimido();
void comando_costo_conquista();
void comando_conquista_mas_barata();
void comando_ayuda();
void comando_ayuda_comandos(const std::string& comando);
void limpiar_consola();
//*****************************************************************
// FIN - FIRMA FUNCIONES
//*****************************************************************

#include "Menu.hxx"

#endif // __MENU__H__

//eof - menu.h
