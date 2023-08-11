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
#include <cstdlib>
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************
void Menu::comando_ayuda_comandos(const std::string& comando){
  if (comando.compare("inicializar") == 0){
    //Diego
    std::cout << " Comando: inicializar <nombre_archivo>\n";
    std::cout << "   Descripcion: Inicializa un nuevo juego. Ingrese el nombre del archivo para reanudar.\n";
    std::cout << "   Para crear una partida nueva, escriba unicamente 'inicializar'.\n";
    std::cout << "   Para cargar una partida existente, escriba 'inicializar' seguido del nombre del archivo de la partida.\n";
  }
  else if (comando.compare("turno") == 0){
    //Santiago
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
    //Nico
    std::cout << " Comando: guardar <nombre_archivo>\n";
    std::cout << "   Descripcion: El estado actual del juego es guardado en un archivo de texto plano,\n";
    std::cout << "   se guarda la cantidad de jugadores, nombre de cada jugador, color de cada jugador,\n";
    std::cout << "   paises que ocupa, etc.\n";
  }
  else if(comando.compare("guardar_comprimido") == 0){
    //Diego
    std::cout << " Comando: guardar_comprimido <nombre_archivo>\n";
    std::cout << "   Descripcion: La partida actual se guarda en un archivo .bin con la informacion comprimida.\n";
  }
  else if (comando.compare("costo_conquista") == 0){
    //Santiago
    std::cout << " Comando: costo_conquista <territorio>\n";
    std::cout << "   Descripcion: Se calcula el costo y la secuencia de territorios a ser conquistados\n";
    std::cout << "   para lograr controlar el territorio dado por el usuario. El territorio desde donde\n";
    std::cout << "   debe atacar debe ser aquel que el jugador tenga controlado mas cerca al dado por el \n";
    std::cout << "   jugador.\n";
  }
  else if (comando.compare("conquista_mas_barata") == 0){
    //Nico
    std::cout << " Comando: conquista_mas_barata'\n";
    std::cout << "   Descripcion: Calcula la conquista mas barata para el jugador de todos los territorios posibles.\n";
    std::cout << "   es decir, aquel territorio que pueda implicar un menor numero de unidades perdidas.\n";
  }
  else if (comando.compare("ayuda") == 0){
    //?
    std::cout << " Comando: ayuda\n";
    std::cout << "   Descripcion: Muestra la lista de comandos disponibles.\n";
  }
  else if (comando.compare("salir") == 0){
    //?
    std::cout << " Comando: salir\n";
    std::cout << "   Descripcion: Termina la ejecucion de la aplicacion.\n";
  }
  else{
    std::cout << " Error: Comando '"<< comando <<"' no reconocido. Escribe 'ayuda' para ver la lista de comandos.\n";
  }
}

void Menu::comando_inicializar_nueva_partida() {
  std::string input, palabra, comando, nombre_partida;
  int cantidad_jugadores;
  char delimitador = ' ';
  bool continuar = false;
  std::cout << "Se creara una partida nueva. \nSi desea cargar una partida existente, regrese al menu principal escribiendo 'salir' y luego escriba 'inicializar <nombre_archivo>' \n";

  do {
    //std::cout << "$ ";
    std::cout << "Ingrese el nombre para la partida: ";
    std::getline(std::cin, input);
    std::stringstream stream(input);
    std::vector<std::string> argumentos;

    // while para ir guardando los argumentos en el vector
    while (getline(stream, palabra, delimitador)) {
      argumentos.push_back(palabra);    
    }
    // Si no ingreso nada, simplemente continua.
    if (argumentos.empty()) {
      continue;
    }
    else if(argumentos.size() > 1) {
      std::cout << "El nombre de la partida no puede estar separada por espacios. \n";
      continue;
    }
    //Regresa al menu principal
    else if (argumentos[0].compare("salir") == 0) {
      return;
    }
    else {
      nombre_partida = argumentos[0];
      continuar = true;
    }
  }
  while(!continuar);

  continuar = false;

  do {
    //std::cout << "$ ";
    std::cout << "Cuantos jugadores tendra la partida "<< nombre_partida <<" (Min 2, Max 6): ";
    std::getline(std::cin, input);
    std::stringstream stream(input);
    std::vector<std::string> argumentos;

    // while para ir guardando los argumentos en el vector
    while (getline(stream, palabra, delimitador)) {
      argumentos.push_back(palabra);    
    }
    // Si no ingreso nada, simplemente continua.
    if (argumentos.empty()) {
      continue;
    }
    else if(argumentos.size() > 1) {
      std::cout << "Ingrese solamente la cantidad de jugadores\n";
      continue;
    }
    //Regresa al menu principal
    else if (argumentos[0].compare("salir") == 0) {
      return;
    }

    else {
      try {
        cantidad_jugadores = std::stoi(argumentos[0]);
        
        if (cantidad_jugadores >= 2 && cantidad_jugadores <= 6) {
          continuar = true;
        } 
        else {
          std::cout << "Error. Debe ingresar entre 2 a 6 jugadores. \n";
        }
      } 
      catch (const std::invalid_argument&) {
        std::cout << "Error. Debe ingresar el numero de jugadores para la partida. \n";
      }
    }
  }
  while(!continuar);

  std::cout << " Inicializar partida nueva (En construccion).\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_inicializar_existente(const std::string& comando) {
  std::cout << " Inicializar partida existente (En construccion).\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_turno(const std::string& comando) {
  std::string input, palabra;
  int cantidad_jugadores;
  char delimitador = ' ';
  bool continuar = false;

  std::string nombre_partida="Prueba";
  std::string nombre_jugador="Cristiano";
  std::string nombre_territorio;
  int cantidad_territorios=2;
  int canti_territorios;
  int fichas_reclamar=7;
  std::string territorios[3], territorios_ataque[2];
  int opcion;
  territorios[0]="cucuta";
  territorios[1]="bogota";
  territorios[2]="chia";
  const int num_territorios= sizeof(territorios)/sizeof(territorios[0]);
  const int num_territorios_ataque= sizeof(territorios_ataque)/sizeof(territorios_ataque[0]);
  bool territorio_valido = false;
  bool territorio_valido_ataque = false;
  int canti_tropas;
  std::string territorio_propio_ataque;
  territorios_ataque[0]="pasto";
  territorios_ataque[1]="madrid";
  int num_dados_atacante, num_dados_defensor;
  int tropas_atacante, tropas_defensor;
  bool retiro=false;
  
  std::cout << " Dentro del comando 'turno'.\n";
  std::cout << "  Su partida es: "<<nombre_partida<<"\n";
  std::cout << "  "<<nombre_jugador<<" puede reclamar "<<fichas_reclamar<<" fichas!!!\n";
  std::cout << "  Actualmente tiene estos territorios:\n";
  
  for(int i=0;i<num_territorios;i++){
    std::cout<<"   -"<<territorios[i]<<"\n";
  }
  
  std::cout << "  En cuantos territorios desea colocar sus tropas?\n";

  do {
    std::cout << "$ ";
    std::getline(std::cin, input);
    std::stringstream stream(input);
    std::vector<std::string> argumentos;

    // while para ir guardando los argumentos en el vector
    while (getline(stream, palabra, delimitador)) {
      argumentos.push_back(palabra);    
    }
    // Si no ingreso nada, simplemente continua.
    if (argumentos.empty()) {
      continue;
    }
    else if(argumentos.size() > 1) {
      std::cout << "Ingrese solamente la cantidad de jugadores";
      continue;
    }
    //Regresa al menu principal
    else if (argumentos[0].compare("salir") == 0) {
      std::cout << "Turno abortado. \n";
      return;
    }

    else {
      try {
        canti_territorios = std::stoi(argumentos[0]);
        continuar = true;
      } 
      catch (const std::invalid_argument&) {
        std::cout << "Error. Debe ingresar la cantidad de territorios. \n";
      }
    }
  }
  while(!continuar);

  continuar = false;
  
  for (int i = 0; i < canti_territorios; i++) {
    std::string nombre_territorio;
    do {
        std::cout << " En cual territorio desea colocar tropas?\n";

        do {
          std::cout << "$ ";
          std::getline(std::cin, input);
          std::stringstream stream(input);
          std::vector<std::string> argumentos;

          // while para ir guardando los argumentos en el vector
          while (getline(stream, palabra, delimitador)) {
            argumentos.push_back(palabra);    
          }
          // Si no ingreso nada, simplemente continua.
          if (argumentos.empty()) {
            continue;
          }
          else if(argumentos.size() > 1) {
            std::cout << "Ingrese solamente el territorio para colocar tropas";
            continue;
          }
          //Regresa al menu principal
          else if (argumentos[0].compare("salir") == 0) {
            std::cout << "Turno abortado. \n";
            return;
          }
          else {
            nombre_territorio = argumentos[0];
              continuar = true;
          }
        }
        while(!continuar);
        continuar = false;

        for (int j = 0; j < num_territorios; j++) {
          if (nombre_territorio == territorios[j]) {
            territorio_valido = true;
            if(canti_territorios=1){
              std::cout<< " Se han agregado las 7 tropas a "<<nombre_territorio<<"\n";
            }else{
              do {
                std::cout << " Cuantas tropas desea colocar en " << nombre_territorio << "\n";
                std::cin >> canti_tropas;
                if (canti_tropas > fichas_reclamar) {
                  std::cout << " Coloco mas fichas de las que tiene\n";
                  } else {
                    fichas_reclamar -= canti_tropas;
                    break;
                    }
                  } while (true);
                    break;
            }
          }
       }
        if (!territorio_valido) {
          std::cout << " Ingrese de nuevo el nombre\n";
        }   
      } while (!territorio_valido);
  }


  std::cout << " Ahora, configuracion de ataque\n";
  
  std::cout << " Desde cual territorio desea atacar?\n";
    do {

      do {
        std::cout << "$ ";
        std::getline(std::cin, input);
        std::stringstream stream(input);
        std::vector<std::string> argumentos;

        // while para ir guardando los argumentos en el vector
        while (getline(stream, palabra, delimitador)) {
          argumentos.push_back(palabra);    
        }
        // Si no ingreso nada, simplemente continua.
        if (argumentos.empty()) {
          continue;
        }
        else if(argumentos.size() > 1) {
          std::cout << "Ingrese solamente el territorio para colocar tropas";
          continue;
        }
        //Regresa al menu principal
        else if (argumentos[0].compare("salir") == 0) {
          std::cout << "Turno abortado. \n";
          return;
        }
        else {
          territorio_propio_ataque = argumentos[0];
          continuar = true;
        }
      }
      while(!continuar);
      continuar = false;

    for (int j = 0; j < num_territorios; j++) {
      if (territorio_propio_ataque == territorios[j]) {
        territorio_valido_ataque = true;
        break;
      }
    }
    if (!territorio_valido_ataque) {
      std::cout << "  Ingrese de nuevo el nombre del territorio para atacar\n";
    }
  } while (!territorio_valido_ataque);
  
  territorio_valido_ataque=false;
  std::cout << " Puede atacar a los siguientes territorios\n";
  for(int i=0;i<num_territorios_ataque;i++){
    std::cout<<"   -"<<territorios_ataque[i]<<"\n";
  }

  std::cout << " Hacia cual territorio desea atacar?\n";
    do {

      do {
        std::cout << "$ ";
        std::getline(std::cin, input);
        std::stringstream stream(input);
        std::vector<std::string> argumentos;

        // while para ir guardando los argumentos en el vector
        while (getline(stream, palabra, delimitador)) {
          argumentos.push_back(palabra);    
        }
        // Si no ingreso nada, simplemente continua.
        if (argumentos.empty()) {
          continue;
        }
        else if(argumentos.size() > 1) {
          std::cout << "Ingrese solamente el territorio para colocar tropas";
          continue;
        }
        //Regresa al menu principal
        else if (argumentos[0].compare("salir") == 0) {
          std::cout << "Turno abortado. \n";
          return;
        }
        else {
          territorio_propio_ataque = argumentos[0];
          continuar = true;
        }
      }
      while(!continuar);
      continuar = false;

    for (int j = 0; j < num_territorios; j++) {
      if (territorio_propio_ataque == territorios_ataque[j]) {
        territorio_valido_ataque = true;
        break;
      }
    }
    if (!territorio_valido_ataque) {
      std::cout << "  No existe, ingrese de nuevo el nombre del territorio para atacar\n";
    }
  } while (!territorio_valido_ataque);
  do {
    std::cout << "  Cuantas tropas tiene para atacar?: \n";
    //std::cin >> tropas_atacante;

    do {
      std::cout << "$ ";
      std::getline(std::cin, input);
      std::stringstream stream(input);
      std::vector<std::string> argumentos;

      // while para ir guardando los argumentos en el vector
      while (getline(stream, palabra, delimitador)) {
        argumentos.push_back(palabra);    
      }
      // Si no ingreso nada, simplemente continua.
      if (argumentos.empty()) {
        continue;
      }
      else if(argumentos.size() > 1) {
        std::cout << "Ingrese solamente la cantidad de tropas";
        continue;
      }
      //Regresa al menu principal
      else if (argumentos[0].compare("salir") == 0) {
        std::cout << "Turno abortado. \n";
        return;
      }

      else {
        try {
          tropas_atacante = std::stoi(argumentos[0]);
          continuar = true;
        } 
        catch (const std::invalid_argument&) {
          std::cout << "Error. Debe ingresar la cantidad de tropas. \n";
        }
      }
    }
    while(!continuar);
    continuar = false;

  } while (tropas_atacante <= 0);

  // Defensor elige la cantidad de tropas
  do {
    std::cout << "  Cuantas tropas tiene para defender?: \n";
    //std::cin >> tropas_defensor;

    do {
      std::cout << "$ ";
      std::getline(std::cin, input);
      std::stringstream stream(input);
      std::vector<std::string> argumentos;

      // while para ir guardando los argumentos en el vector
      while (getline(stream, palabra, delimitador)) {
        argumentos.push_back(palabra);    
      }
      // Si no ingreso nada, simplemente continua.
      if (argumentos.empty()) {
        continue;
      }
      else if(argumentos.size() > 1) {
        std::cout << "Ingrese solamente la cantidad de tropas";
        continue;
      }
      //Regresa al menu principal
      else if (argumentos[0].compare("salir") == 0) {
        std::cout << "Turno abortado. \n";
        return;
      }

      else {
        try {
          tropas_defensor = std::stoi(argumentos[0]);
          continuar = true;
        } 
        catch (const std::invalid_argument&) {
          std::cout << "Error. Debe ingresar la cantidad de tropas. \n";
        }
      }
    }
    while(!continuar);
    continuar = false;

  } while (tropas_defensor <= 0);

  std::cout << " Momento de los dados!!!\n";
  
  while (tropas_atacante > 0 && tropas_defensor > 0) {
    // Mostrar opciones al atacante
    std::cout << "  Opciones:\n";
    std::cout << "   1. Lanzar dados\n";
    std::cout << "   2. Retirarse\n";
    
    std::cout << "  Elija una opcion: ";

    do {
      std::cout << "$ ";
      std::getline(std::cin, input);
      std::stringstream stream(input);
      std::vector<std::string> argumentos;

      // while para ir guardando los argumentos en el vector
      while (getline(stream, palabra, delimitador)) {
        argumentos.push_back(palabra);    
      }
      // Si no ingreso nada, simplemente continua.
      if (argumentos.empty()) {
        continue;
      }
      else if(argumentos.size() > 1) {
        std::cout << "Ingrese solamente la cantidad de tropas";
        continue;
      }
      //Regresa al menu principal
      else if (argumentos[0].compare("salir") == 0) {
        std::cout << "Turno abortado. \n";
        return;
      }

      else {
        try {
          opcion = std::stoi(argumentos[0]);
          continuar = true;
        } 
        catch (const std::invalid_argument&) {
          std::cout << "Error. Debe ingresar la cantidad de tropas. \n";
        }
      }
    }
    while(!continuar);
    continuar = false;

    if (opcion == 1) {
      int num_dados_atacante, num_dados_defensor;
  
      // Atacante elige la cantidad de dados a lanzar
      do {
        std::cout << "  Cuantos dados desea lanzar el atacante (1, 2 o 3)?: ";
        //std::cin >> num_dados_atacante;

        do {
          std::cout << "$ ";
          std::getline(std::cin, input);
          std::stringstream stream(input);
          std::vector<std::string> argumentos;

          // while para ir guardando los argumentos en el vector
          while (getline(stream, palabra, delimitador)) {
            argumentos.push_back(palabra);    
          }
          // Si no ingreso nada, simplemente continua.
          if (argumentos.empty()) {
            continue;
          }
          else if(argumentos.size() > 1) {
            std::cout << "Ingrese solamente la cantidad de tropas";
            continue;
          }
          //Regresa al menu principal
          else if (argumentos[0].compare("salir") == 0) {
            std::cout << "Turno abortado. \n";
            return;
          }

          else {
            try {
              num_dados_atacante = std::stoi(argumentos[0]);
              continuar = true;
            } 
            catch (const std::invalid_argument&) {
              std::cout << "Error. Debe ingresar la cantidad de tropas. \n";
            }
          }
        }
        while(!continuar);
        continuar = false;

      } while (num_dados_atacante < 1 || num_dados_atacante > 3);
  
      // Defensor elige la cantidad de dados a lanzar
      do {
        std::cout << "  Cuantos dados desea lanzar el defensor (1 o 2)?: ";

        do {
          std::cout << "$ ";
          std::getline(std::cin, input);
          std::stringstream stream(input);
          std::vector<std::string> argumentos;

          // while para ir guardando los argumentos en el vector
          while (getline(stream, palabra, delimitador)) {
            argumentos.push_back(palabra);    
          }
          // Si no ingreso nada, simplemente continua.
          if (argumentos.empty()) {
            continue;
          }
          else if(argumentos.size() > 1) {
            std::cout << "Ingrese solamente la cantidad de tropas";
            continue;
          }
          //Regresa al menu principal
          else if (argumentos[0].compare("salir") == 0) {
            std::cout << "Turno abortado. \n";
            return;
          }

          else {
            try {
              num_dados_defensor = std::stoi(argumentos[0]);
              continuar = true;
            } 
            catch (const std::invalid_argument&) {
              std::cout << "Error. Debe ingresar la cantidad de tropas. \n";
            }
          }
        }
        while(!continuar);
        continuar = false;

      } while (num_dados_defensor < 1 || num_dados_defensor > 2);
  
      // Lanzamiento de dado aleatorio para el atacante y el defensor
      int dados_atacante[num_dados_atacante];
      int suma_dados_atacante = 0;
      for (int i = 0; i < num_dados_atacante; i++) {
        dados_atacante[i] = rand() % 6 + 1; // Número aleatorio entre 1 y 6
        suma_dados_atacante += dados_atacante[i]; // Sumar al total de la suma del atacante
      }
  
      int dados_defensor[num_dados_defensor];
      int suma_dados_defensor = 0;
      for (int i = 0; i < num_dados_defensor; i++) {
        dados_defensor[i] = rand() % 6 + 1; // Número aleatorio entre 1 y 6
        suma_dados_defensor += dados_defensor[i]; // Sumar al total de la suma del defensor
      }
  
      // Mostrar resultados de los dados
      std::cout << "  ------------------------------------\n";
      std::cout << "  Resultados del lanzamiento de dados:\n";
      std::cout << "   Atacante: ";
      for (int i = 0; i < num_dados_atacante; i++) {
        std::cout << dados_atacante[i] << " ";
      }
      std::cout << "\n";
      std::cout << "   Defensor: ";
      for (int i = 0; i < num_dados_defensor; i++) {
        std::cout << dados_defensor[i] << " ";
      }
      std::cout << "\n";
  
      // Comparar los resultados de los dados y descontar tropas
      for (int i = 0; i < std::min(num_dados_atacante, num_dados_defensor); i++) {
        if (dados_atacante[i] > dados_defensor[i]) {
          tropas_defensor--;
        } else {
          tropas_atacante--;
        }
      }
  
      // Mostrar cantidad de tropas restantes después del enfrentamiento
      std::cout << "  Tropas restantes:\n";
      std::cout << "   Atacante: " << tropas_atacante << "\n";
      std::cout << "   Defensor: " << tropas_defensor << "\n";
  
    } else if (opcion == 2) {
      std::cout << "  El atacante se retira. Fin del ataque.\n";
      retiro=true;
      break;
    } else {
      std::cout << "  Opcion invalida. Por favor, elija una opcion valida.\n";
    }
  }

  // Mostrar el resultado final del ataque
  if (tropas_atacante <= 0) {
    std::cout << "  El atacante ha perdido todas sus tropas.\n";
  }
  else if(retiro=true){
  } 
  else {
    std::cout << "  El defensor ha perdido todas sus tropas.\n";
  }
  std::cout << " Por ultimo el atacante procedera a reagrupar tropas. \n";
  std::cout << " Para esto se deben tener en cuenta los territorios vecinos. \n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_guardar(const std::string& nombreArchivo) {
  std::cout << " Dentro del comando 'guardar'.\n";
  std::cout << "  Si el comando fue correcto: La partida ha sido guardada correctamente con el nombre de archivo: '" << nombreArchivo << "'.\n";
  std::cout << "  Si no hay ningun juego inicializado: Esta partida no ha sido inicializada correctamente.\n";
  std::cout << "  Si hubo algun error al guardar: La partida no ha sido guardada correctamente.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_guardar_comprimido(const std::string& nombreArchivo) {
  std::cout << " Dentro del comando 'guardar_comprimido'.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_costo_conquista(const std::string& territorio) {
  std::cout << " Dentro del comando 'costo_conquista'.\n";
  std::cout << "   Ejemplo ejecucion correcta: Para conquistar el territorio ''" << territorio << "'' debe\n";
  std::cout << "   atacar desde <territorio_1>, pasando por <territorio_2> ,<territorio_3>. Debe conquistar <n> unidades de ejercito.\n";
  std::cout << "   Se calcula el costo y secuencia de territorios a ser conquistados para lograr\n";
  std::cout << "   controlar el territorio dado por el usuario. Aclarar que, el territorio donde se debe\n";
  std::cout << "   atacar debe ser el aquel que el jugador tenga controlado más cerca al dado por el jugador.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

void Menu::comando_conquista_mas_barata() {
  std::cout << " Dentro del comando 'conquista_mas_barata'.\n";
  std::cout << "  Aqui, de todos los territorios posibles, se calcula aquel que pueda implicar un menor numero de unidades de ejercito perdidas.\n";
  std::cout << "  Esta informacion se analiza desde el punto de vista del jugador que tiene el turno de juego.\n";
  std::cout << "  Ejemplo ejecucion correcta:\n";
  std::cout << "    La conquista mas barata es avanzar sobre el territorio <territorio_1> desde el territorio <territorio_2>.\n";
  std::cout << "    Para conquistar el territorio <territorio_1>, debe atacar desde <territorio_2>, pasando por los territorios <territorio_3>, <territorio_4>, ..., <territorio_m>.\n"; 
  std::cout << "    Debe conquistar <n> unidades de ejercito.\n";
  std::cout << "  Si no hay ningun juego inicializado: Esta partida no ha sido inicializada correctamente.\n";
  std::cout << "  Si el juego ya termino: Esta partida ya tuvo ganador.\n";
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

  std::cout << "---------------------------------------------------------------------BIENVENIDO!----------------------------------------------------------------------\n";
  std::cout << "                                             ,&&@&@@@@@@@@@@@@@&                                                                                      \n";
  std::cout << "                                                &@&@&@@@&@@@&@&&                                                                                      \n";
  std::cout << "                    *@@@@@@@@@@@&@@@@@@@@@@&      &@@@@@@@@&&*                                     %@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&%              \n";
  std::cout << "    .&@@@@@@@@@@@@&@@@@@@@@@@@@@&@@@@@    @@@&,   &@@@@@@&&                   @@&@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@&&.   \n";
  std::cout << "     &@@@@@@@@@@@@@@@@@@@@@@@@@@&@@& &&.  /&&&     &&&@&*      /&.         &&@&@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@&////,   \n";
  std::cout << "      @&&@%////@@@@@@@@@&@@@@@@@&@%     #&@@                               @@@@@&@@@@@@@&@@@@@@@&@@@@@@@&@@@@@@@&@@@@@@@&@@@@@@@@///////&@&%          \n";
  std::cout << "                 ,&@@@@@@@@@@@@@&@&                                                                                @@@@@@@@@@@@@@             \n";
  std::cout << "                    &&@@@@@@@@@@&@   @@@@@@@@@@@@@@@@@,     @@@@@@@@@@&     @@@@@@@@@@@@   @@@@@@@@@@@   @@@@@@  @@@@@@@@@@@@@@                     \n";
  std::cout << "                     ,@@@@@@@@@@&@@@  @@@@@@@    @@@@@@@,     @@@@@@@     @@@@@       @@%     @@@@@@@     &@@@  .@@@@@@@@@@@&@@                       \n";
  std::cout << "                     ,&@&@&@&@&@&@&@  @@@@@@@    #@@@@@@#     @@@@@@@     @@@@@@@      @%     @@@@@@@   @@@@   @&@&@&@&@&@&&#   @                     \n";
  std::cout << "                       @@@@@@@@@&@@@  @@@@@@@    @@@@@@%      @@@@@@@     @@@@@@@@@@          @@@@@@@  @@@@   @@@@@@@@@@  %/  *@                      \n";
  std::cout << "                         #@@@@@@&@@@  @@@@@@@@@@@@@/          @@@@@@@       @@@@@@@@@@@@@     @@@@@@@@@@@@@@   @&@@@@@@@    /                         \n";
  std::cout << "                            @@@@&     @@@@@@@   @@@@@@@       @@@@@@@           %@@@@@@@@@    @@@@@@@ @@@@@@@   &@@@@@@&&                              \n";
  std::cout << "                              #@&@#   @@@@@@@   &@@@@@@%      @@@@@@@     @@        @@@@@@    @@@@@@@  @@@@@@@@   @@@@.                                \n";
  std::cout << "                                   (  @@@@@@@    @@@@@@@      @@@@@@@     @@@&      @@@@@     @@@@@@@    @@@@@@@@       &                             \n";
  std::cout << "                                     @@@@@@@@@@    @@@@@@@  @@@@@@@@@@@     @@@@@@@@@@      @@@@@@@@@@@    @@@@@@@@   . .&                            \n";
  std::cout << "                                        &&@@@@@@@&@                        &&%,    .#&@@@@                    %/.   *&#                               \n";
  std::cout << "                                        @@@@&@@@&@@@&&&&                     @@@&@@@&@@&                        %@  &@*&     @((#                     \n";
  std::cout << "                                        @@@@@@@@@@@@@@@&%                    @@@@@@@@@@(                           ######         %.                  \n";
  std::cout << "                                          &&@@@@&@@@@@&&(                    @@@&@@@@@&(  &&                            .&@@@@@@@/                    \n";
  std::cout << "                                           @@@@@@@@@@&                       *&@@@@@@,   @@                           %@@@@@@@@@&@&&                  \n";
  std::cout << "                                           @@@@@&@@&                          @@&@@@@,                               &@@&@@@@@@@&@@@@                 \n";
  std::cout << "                                           @@@@@@&@.                          %@@@@.                                 &@@@@###&@@&@@@@                 \n";
  std::cout << "                                          @&@@&&&                                                                              *&&&.         @        \n";
  std::cout << "                                          &&@@.                                                                                   &         &&        \n";
  std::cout << "                                          &@(                                                                                                         \n";
  std::cout << "                                          &@(                                                                                                       \n";
  std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";

  std::cout << "  Escribe 'ayuda' para ver la lista de comandos disponibles.\n";
  std::cout << " Porfavor ingrese un comando: \n";

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
      if (argumentos.size() < 2) {
        std::cout << "Error: Debe ingresar el número de turno.\n";
      } else {
        try {
          int numero_turno = std::stoi(argumentos[1]);
          Menu::comando_turno(argumentos[1]);
          } catch (std::invalid_argument&) {
            std::cout << "Error: El segundo argumento debe ser un número.\n";
          }
      }
      } else if (argumentos[0].compare("guardar") == 0) {
      if(argumentos.size() < 2){
        std::cout << " Error: Debe ingresar el nombre del archivo para guardar la partida.\n";
        continue;
      } else if (argumentos[1].empty()){
        std::cout << "Error: El nombre del archivo no puede estar vacio.\n";
        continue;
      }
      else{
        Menu::comando_guardar(argumentos[1]);
      }
      
    } else if (argumentos[0].compare("guardar_comprimido") == 0) {
      if(argumentos.size() < 2){
        std::cout << " Error: Debe ingresar el nombre del archivo para guardar la partida comprimida.\n";
        continue;
      } 
      else if (argumentos[1].empty()){
        std::cout << "Error: El nombre del archivo no puede estar vacio.\n";
        continue;
      }
      else{
        //La funcion posteriormente guardara el archivo en un .bin
        Menu::comando_guardar_comprimido(argumentos[1]);
      }
    } else if (argumentos[0].compare("costo_conquista") == 0) {
        if(argumentos.size() < 2){
          std::cout << " Error: Debe ingresar el nombre del territorio para calcular la conquista.\n";
          continue;
        } 
        else if (argumentos[1].empty()){
          std::cout << "Error: El territorio vacio no existe.\n";
          continue;
        }
        else{
          //La funcion posteriormente guardara el archivo en un .bin
          Menu::comando_costo_conquista(argumentos[1]);
      }
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
