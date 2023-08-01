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


//************************************************************************
// INICIO - LIBRERIAS
//************************************************************************
#include "Menu.h"
#include <iostream>
#include <sstream>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************
void Menu::comando_ayuda_comandos(const std::string& comando){
  if (comando.compare("inicializar") == 0){
    std::cout << " Comando: inicializar <nombre_archivo>\n";
    std::cout << "   Descripcion: Inicializa un nuevo juego. Ingrese el nombre del archivo para reanudar.\n";
  }
  else if (comando.compare("turno") == 0){
    std::cout << " Comando: turno <id_jugador>\n";
    std::cout << "   Descripcion: Primero, informa al jugador la cantidad de unidades puede reclamar,\n";
    std::cout << "   para luego preguntarle en cuales de sus territorios las quiere asignar y en que\n";
    std::cout << "   cantidad. Segundo, pregunta la configuración del ataque donde se elige desde cual\n"; 
    std::cout << "   territorio a cual territorio se dirigen a atacar. Tercero, deberia informar acerca\n"; 
    std::cout << "   de los valores de los dados y la cantidad de tropas que se gano o perdio. Por \n"; 
    std::cout << "   ultimo, pregunta al jugadorlos territorios que desea seleccionar para la ,\n"; 
    std::cout << "   fortificacion asi como la cantidad de unidades que se trasladaran de uno al otro.\n";
  }
  else if (comando.compare("guardar") == 0){
    std::cout << " Comando: guardar <nombre_archivo>\n";
    std::cout << "   Descripcion: El estado actual del juego es guardado en un archivo de texto plano,\n";
    std::cout << "   se guarda la cantidad de jugadores, nombre de cada jugador, color de cada jugador,\n";
    std::cout << "   paises que ocupa, etc.\n";
  }
  else if(comando.compare("guardar_comprimido") == 0){
    std::cout << " Comando: guardar_comprimido <nombre_archivo>\n";
    std::cout << "   Descripcion: La partida actual se guarda en un archivo .bin con la informacion comprimida.\n";
  }
  else if (comando.compare("costo_conquista") == 0){
    std::cout << " Comando: costo_conquista <territorio>\n";
    std::cout << "   Descripcion: Se calcula el costo y la secuencia de territorios a ser conquistados\n";
    std::cout << "   para lograr controlar el territorio dado por el usuario. El territorio desde donde\n";
    std::cout << "   debe atacar debe ser aquel que el jugador tenga controlado mas cerca al dado por el \n";
    std::cout << "   jugador.\n";
  }
  else if (comando.compare("conquista_mas_barata") == 0){
    std::cout << " Comando: conquista_mas_barata'\n";
    std::cout << "   Descripcion: Calcula la conquista mas barata para el jugador de todos los territorios posibles.\n";
    std::cout << "   es decir, aquel territorio que pueda implicar un menor numero de unidades perdidas.\n";
  }
  else if (comando.compare("ayuda") == 0){
    std::cout << " Comando: ayuda\n";
    std::cout << "   Descripcion: Muestra la lista de comandos disponibles.\n";
  }
  else if (comando.compare("salir") == 0){
    std::cout << " Comando: salir\n";
    std::cout << "   Descripcion: Termina la ejecucion de la aplicacion.\n";
  }
  else{
    std::cout << " Error: Comando '"<< comando <<"' no reconocido. Escribe 'ayuda' para ver la lista de comandos.\n";
  }
}

void Menu::comando_inicializar_nueva_partida() {
  std::cout << " Dentro del comando 'inicializar' para nueva partida.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_inicializar_existente(const std::string& comando) {
  std::cout << " Dentro del comando 'inicializar' para partida existente.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_turno() {
  std::cout << " Dentro del comando 'turno'.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_guardar() {
  std::cout << " Dentro del comando 'guardar'.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_guardar_comprimido() {
  std::cout << " Dentro del comando 'guardar_comprimido'.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_costo_conquista() {
  std::cout << " Dentro del comando 'costo_conquista'.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_conquista_mas_barata() {
  std::cout << " Dentro del comando 'conquista_mas_barata'.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_ayuda() {
  std::cout << " Los siguientes son los comandos disponibles: \n";
  std::cout << "   inicializar\n";
  std::cout << "   turno\n";
  std::cout << "   guardar\n";
  std::cout << "   guardar_comprimido\n";
  std::cout << "   costo_conquista\n";
  std::cout << "   conquista_mas_barata\n";
  std::cout << "   salir\n";
  std::cout << " Para mas informacion de un comando, escriba 'ayuda' seguido del comando.\n";
}

void Menu::limpiar_consola() {
  //Limpia la consola
  if (system("clear") != 0 && system("cls") != 0) {  
    std::cout<<" Error al reiniciar la consola.\n";
  }
}

void Menu::interaccion_usuario(){
  std::string input, palabra, comando;
  char delimitador = ' ';

  Menu::limpiar_consola();

  std::cout << "--------------------------------BIENVENIDO!--------------------------------\n";
  std::cout << "(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((\n";
  std::cout << "((((((/****************/((((((((.    (((((((((((((//////////(((((((((((((((\n";
  std::cout << "((((((* #################  /((( *#### (((((((((((( .######* (((((((((((((((\n";
  std::cout << "((((((* ######     ######## (((. ###  ((((          ,#####* (((((((((((((((\n";
  std::cout << "(((((((((( ####(   ##* .###   ####### * ,##########   ####**####### (((((((\n";
  std::cout << "(((((((((( ####### ######,    (######  ####     ###   ####* *#####/ (((((((\n";
  std::cout << "(((((((((( ###((. //######      ,####  ###########    ####*##### ((((((((((\n";
  std::cout << "((((((*    #####     . #(#, #   /####    ,#########   ####* /####    ((((((\n";
  std::cout << "((((((* ###########   ####### ####### .###    /###(.######* #######. ((((((\n";
  std::cout << "((((((*                /##(               .(###*                     ((((((\n";
  std::cout << "(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((\n";
  std::cout << "---------------------------------------------------------------------------\n";

  std:: cout << " Porfavor ingrese un comando: \n";

  while (1) {
    std::cout << "$ ";
    std::getline(std::cin, input);

    std::stringstream stream(input);
    std::vector<std::string> argumentos;

    // while para ir guardando los argumentos en el vector, delimitados por
    // espacio.
    while (getline(stream, palabra, delimitador)) {
      argumentos.push_back(palabra);
    }

    // Si no ingreso nada, simplemente continua.
    if (argumentos.empty()) {
      continue;
    }

    // Revisar cual comando fue ingresado e ir a la funcion correspondiente.
    if (argumentos[0].compare("ayuda") == 0) {
      if (argumentos.size() == 1) {
        Menu::comando_ayuda();
      } else {
        Menu::comando_ayuda_comandos(argumentos[1]);
      }
    } else if (argumentos[0].compare("inicializar") == 0) {
      if (argumentos.size() == 1) {
        Menu::comando_inicializar_nueva_partida();
      } else {
        Menu::comando_inicializar_existente(argumentos[1]);
      }
    } else if (argumentos[0].compare("turno") == 0) {
      Menu::comando_turno();
    } else if (argumentos[0].compare("guardar") == 0) {
      Menu::comando_guardar();
    } else if (argumentos[0].compare("guardar_comprimido") == 0) {
      Menu::comando_guardar_comprimido();
    } else if (argumentos[0].compare("costo_conquista") == 0) {
      Menu::comando_costo_conquista();
    } else if (argumentos[0].compare("conquista_mas_barata") == 0) {
      Menu::comando_conquista_mas_barata();
    } else if (argumentos[0].compare("clear") == 0) {
      Menu::limpiar_consola();
    } else if (argumentos[0].compare("salir") == 0) {
      std::cout << " Fin del Programa\n";
      exit(0);
    } else {
      std::cout << " Error: Comando '" << argumentos[0] << "' no reconocido. Escribe 'ayuda' para ver la lista de comandos disponibles.\n";
    }
  }
}
//************************************************************************
// FIN - FUNCIONES
//************************************************************************

// eof - Menu.hxx
