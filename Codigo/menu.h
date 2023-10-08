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
    static void comando_inicializar_existente(std::string comando);
    static void comando_turno(std::string comando);
    std::string partida_a_JSON();
    static void comando_guardar(std::string nombreArchivo);
    static void comando_guardar_comprimido(std::string nombreArchivo);
    static void comando_costo_conquista(std::string territorio);
    static void comando_conquista_mas_barata();
    static void comando_ayuda();
    static void comando_ayuda_comandos(std::string comando);
    static void limpiar_consola();
    static void interaccion_usuario();
    static void imagen_risk();
    static bool contieneSoloEspacios(std::string str);

};

//*****************************************************************
// FIN - CLASE MENU
//*****************************************************************

#include "menu.hxx"

#endif // __MENU__H__
