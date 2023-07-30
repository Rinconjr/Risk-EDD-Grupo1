//*****************************************************************
// Autores: Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
// Proyecto juego risk - Estructuras de datos
// Compilación: "g++ -std=c++11 risk.cxx risk.cpp -o ejecutable"
// Ejecución: "./ejecutable"
// 
//
//  Archivo creado por Juan Diego Echeverry, Santiago Yañez y Nicolás Rincón
//  Fecha de inicio: 28/07/23
//  Fecha de finalización: ---
//*****************************************************************


//*****************************************************************
// INICIO - LIBRERIAS INCLUIDAS
//*****************************************************************
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "risk.h"
//*****************************************************************
// FIN - LIBRERIAS INCLUIDAS
//*****************************************************************


//*********************************************************************************************************
//  INICIO - PROGRAMA PRINCIPAL
//*********************************************************************************************************
int main()
{
  std::string input, palabra, comando;
  char delimitador = ' ';

  //Limpia la consola
  if (system("clear") != 0 && system("cls") != 0) {  
    std::cout<<"$ Error al reiniciar la consola.\n";
  }
  
  std::cout << "----RISK----\n";

  while(1){
    std::cout << "$ ";
    std::getline(std::cin, input);

    std::stringstream stream(input);
    std::vector<std::string> argumentos;

    //while para ir guardando los argumentos en el vector, delimitados por espacio.
    while(getline(stream, palabra, delimitador)){
      argumentos.push_back(palabra);
    }

    //Si no ingreso nada, simplemente continua.
    if(argumentos.empty()){
      continue;
    }

    //Revisar cual comando fue ingresado e ir a la funcion correspondiente.
    if (argumentos[0] == "ayuda") {
      if(argumentos.size() == 1){
        comando_ayuda();
      }
      else{
        comando_ayuda_comandos(argumentos[1]);
      }
    }
    else if(argumentos[0] == "inicializar"){
      comando_inicializar();
    }
    else if(argumentos[0] == "turno"){
      comando_turno();
    }
    else if(argumentos[0] == "guardar"){
      comando_guardar();
    }
    else if(argumentos[0] == "guardar_comprimido"){
      comando_guardar_comprimido();
    }
    else if(argumentos[0] == "costo_conquista"){
      comando_costo_conquista();
    }
    else if(argumentos[0] == "conquista_mas_barata"){
      comando_conquista_mas_barata();
    }
    else if(argumentos[0] == "salir"){
      std::cout << "$ Fin del Programa\n";
      exit(0);
    }
    else{
      std::cout << "$ Error: Comando '" << argumentos[0] << "' no reconocido. Escribe 'ayuda' para ver la lista de comandos disponibles.\n";
    }
  }

  return 0;
}
//*********************************************************************************************************
//  FIN - PROGRAMA PRINCIPAL
//*********************************************************************************************************

// eof - risk.cpp
