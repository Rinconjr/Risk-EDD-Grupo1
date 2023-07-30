#include "risk.h"
#include <iostream>
#include <sstream>

void comando_ayuda_comandos(const std::string& comando){
  if (comando == "inicializar"){
    //Diego
    std::cout << "$ Comando: Inicializar <nombre_archivo>\n";
    std::cout << "$   Descripcion: Inicializa un nuevo juego. Ingrese el nombre del archivo para reanudar.\n";
  }
  else if (comando == "turno"){
    //Santiago
    std::cout << "$ Comando: turno <id_jugador>\n";
    std::cout << "$   Descripcion: Primero, informa al jugador la cantidad de unidades puede reclamar,\n";
    std::cout << "$   para luego preguntarle en cuales de sus territorios las quiere asignar y en que\n";
    std::cout << "$   cantidad. Segundo, pregunta la configuración del ataque donde se elige desde cual\n"; 
    std::cout << "$   territorio a cual territorio se dirigen a atacar. Tercero, deberia informar acerca\n"; 
    std::cout << "$   de los valores de los dados y la cantidad de tropas que se gano o perdio. Por \n"; 
    std::cout << "$   ultimo, pregunta al jugadorlos territorios que desea seleccionar para la ,\n"; 
    std::cout << "$   fortificacion asi como la cantidad de unidades que se trasladaran de uno al otro.\n";
  }
  else if (comando == "guardar"){
    //Nico
    std::cout << "$ Comando: guardar <nombre_archivo>\n";
    std::cout << "$   Descripcion: El estado actual del juego es guardado en un archivo de texto plano,\n";
    std::cout << "$   se guarda la cantidad de jugadores, nombre de cada jugador, color de cada jugador,\n";
    std::cout << "$   paises que ocupa, etc.\n";
  }
  else if(comando == "guardar_comprimido"){
    //Diego
    std::cout << "$ Comando: guardar_comprimido <nombre_archivo>\n";
    std::cout << "$   Descripcion: La partida actual se guarda en un archivo .bin con la informacion comprimida.\n";
  }
  else if (comando == "costo_conquista"){
     //Santiago
    std::cout << "$ Comando: costo_conquista <territorio>\n";
    std::cout << "$   Descripcion: Se calcula el costo y la secuencia de territorios a ser conquistados\n";
    std::cout << "$   para lograr controlar el territorio dado por el usuario. El territorio desde donde\n";
    std::cout << "$   debe atacar debe ser aquel que el jugador tenga controlado mas cerca al dado por el \n";
    std::cout << "$   jugador.\n";
  }
  else if (comando == "conquista_mas_barata"){
    //Nico
    std::cout << "$ Comando: conquista_mas_barata'\n";
    std::cout << "$   Descripcion: Calcula la conquista mas barata para el jugador de todos los territorios posibles.\n";
    std::cout << "$   es decir, aquel territorio que pueda implicar un menor numero de unidades perdidas.\n";
  }
  else if (comando == "ayuda"){
    //?
    std::cout << "$ Comando: ayuda\n";
    std::cout << "$   Descripcion: Muestra la lista de comandos disponibles.\n";
  }
  else if (comando == "salir"){
    //?
    std::cout << "$ Comando: salir\n";
    std::cout << "$   Descripcion: Termina la ejecucion de la aplicacion.\n";
  }
  else{
    std::cout << "$ Error: Comando '"<< comando <<"' no reconocido. Escribe 'ayuda' para ver la lista de comandos.\n";
  }
}

void comando_inicializar() {
  std::cout << "$ Dentro del comando 'inicializar'.\n";
  std::cout << "$ Presione enter para continuar.";
  std::cin.ignore();
}

void comando_turno() {
  std::cout << "$ Dentro del comando 'turno'.\n";
  std::cout << "$ Presione enter para continuar.";
  std::cin.ignore();
}

void comando_guardar() {
  std::cout << "$ Dentro del comando 'guardar'.\n";
  std::cout << "$ Presione enter para continuar.";
  std::cin.ignore();
}

void comando_guardar_comprimido() {
  std::cout << "$ Dentro del comando 'guardar_comprimido'.\n";
  std::cout << "$ Presione enter para continuar.";
  std::cin.ignore();
}

void comando_costo_conquista() {
  std::cout << "$ Dentro del comando 'costo_conquista'.\n";
  std::cout << "$ Presione enter para continuar.";
  std::cin.ignore();
}

void comando_conquista_mas_barata() {
  std::cout << "$ Dentro del comando 'conquista_mas_barata'.\n";
  std::cout << "$ Presione enter para continuar.";
  std::cin.ignore();
}

void comando_ayuda() {
  std::cout << "$ Los siguientes son los comandos disponibles: \n";
  std::cout << "$   inicializar\n";
  std::cout << "$   turno\n";
  std::cout << "$   guardar\n";
  std::cout << "$   guardar_comprimido\n";
  std::cout << "$   costo_conquista\n";
  std::cout << "$   conquista_mas_barata\n";
  std::cout << "$   salir\n";
  std::cout << "$ Para mas informacion de un comando, escriba 'ayuda' seguido del comando.\n";
}

// eof - risk.cxx