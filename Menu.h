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
// INICIO - CLASE MENU
//*****************************************************************

class Menu{
  public:
    static void comando_inicializar_nueva_partida();
    static void comando_inicializar_existente(const std::string& comando);
    static void comando_turno();
    static void comando_guardar();
    static void comando_guardar_comprimido();
    static void comando_costo_conquista();
    static void comando_conquista_mas_barata();
    static void comando_ayuda();
    static void comando_ayuda_comandos(const std::string& comando);
    static void limpiar_consola();
    static void interaccion_usuario();

};

//*****************************************************************
// FIN - CLASE MENU
//*****************************************************************

#include "Menu.hxx"

#endif // __MENU__H__
