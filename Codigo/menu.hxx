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
#include "menu.h"
#include "continente.h"
#include "carta.h"
#include "dado.h"
#include "pais.h"
#include "jugador.h"
#include "partida.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

#include <windows.h> //Esto es para windows

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Esto es para cambiar los colores de forma global
//************************************************************************
// FIN - LIBRERIAS
//************************************************************************


//************************************************************************
// INICIO - FUNCIONES
//************************************************************************

//La función se emplea en situaciones en las cuales el usuario requiere asistencia en relación al funcionamiento de alguno de los comandos. Se procederá a verificar cuál es el comando específico con respecto al cual necesita ayuda, y se le proporcionará la asistencia correspondiente.
void Menu::comando_ayuda_comandos(const std::string& comando){
  if (comando.compare("inicializar") == 0){
    std::cout << " Comando: inicializar <nombre_archivo>\n";
    std::cout << "   Descripcion: Inicializa un nuevo juego. Ingrese el nombre del archivo para reanudar.\n";
    std::cout << "   Para crear una partida nueva, escriba unicamente 'inicializar'.\n";
    std::cout << "   Para cargar una partida existente, escriba 'inicializar' seguido del nombre del archivo de la partida.\n";
  }
  else if (comando.compare("turno") == 0){
    std::cout << " Comando: turno <id_jugador>\n";
    std::cout << "   Descripcion: Informa al jugador la cantidad de unidades que puede reclamar para\n";
    std::cout << "   para saber en cuales de sus territorios las quiere asignar y en que cantidad.\n";
    std::cout << "   Segundo, pregunta la configuración del ataque, se elige desde y hacia cual territorio\n"; 
    std::cout << "   se quiere a atacar. Tercero, entra en juego los valores de los dados y la cantidad\n"; 
    std::cout << "   de tropas que se gano o perdio. Por ultimo, pregunta al jugador los territorios que\n"; 
    std::cout << "   desea seleccionar para la fortificacion asi como la cantidad de unidades que se\n"; 
    std::cout << "   se trasladaran de uno al otro.\n";
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

//Es la función con la que se inicializa el juego
void Menu::comando_inicializar_nueva_partida() {
  std::string input, palabra, comando, nombre_partida;
  int cantidad_jugadores;
  char delimitador = ' ';
  bool continuar = false;
  std::cout << "Se creara una partida nueva. \nSi desea cargar una partida existente, regrese al menu principal escribiendo 'salir' y luego escriba 'inicializar <nombre_archivo>' sad\n";

  do {
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

  //Crear la partida
  Partida mipartida;

  //Guardar el nombre de la partida
  mipartida.FijarNombre(nombre_partida);

  std::cout << "Recuerde que si desea volver al menu principal en cualquier momento escribiendo: 'salir'. \n";

  //Crear vector tipo partidas e iterador
  std::vector<std::string> tipopartidas;
  std::vector<std::string>::iterator tipopartidasIt;

  //Agregar colores de la partida
  tipopartidas.push_back("MisionSecreta");
  tipopartidas.push_back("Normal");

  continuar = false;

  //Mostrar tipos de partida disponibles
  std::cout << "Los siguientes son los tipos de partida disponibles: " << std::endl;

  for(tipopartidasIt = tipopartidas.begin(); tipopartidasIt != tipopartidas.end(); tipopartidasIt++){
    std::cout << "   - " << *tipopartidasIt << std::endl;
  }

  //Preguntar el tipo de la partida
  do {
    std::cout << "Que tipo de partida desea crear para '"<< nombre_partida <<"': ";
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
      std::cout << "Ingrese solamente el tipo de la partida\n";
      continue;
    }
    //Regresa al menu principal
    else if (argumentos[0].compare("salir") == 0) {
      return;
    }
    else {
      //Revisar si el tipo de partida ingresada existe
      bool encontrado = false;

      for(tipopartidasIt = tipopartidas.begin(); tipopartidasIt != tipopartidas.end(); tipopartidasIt++){
        if(argumentos[0].compare(*tipopartidasIt) == 0){
          encontrado = true;
        }
      }
      if(encontrado == false){
        std::cout << "Tipo partida: '" << argumentos[0] << "' no encontrado. Porfavor ingrese un tipo de partida valido. \n";
      } else{
        mipartida.FijarTipoJuego(argumentos[0]); //Asignar tipo partida a partida
        continuar = true;
      }
    }
  }
  while(!continuar);

  //Preguntar el numero de jugadores
  continuar = false;

  do {
    std::cout << "Cuantos jugadores tendra la partida '" << nombre_partida << "' (Min 2, Max 6): ";
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


  //Crear queue jugadores e iterador
  std::queue<Jugador> jugadoresPartida;

  //Crear vector colores e iterador
  std::vector<std::string> colores;
  std::vector<std::string>::iterator coloresIt;

  //Agregar colores de la partida
  colores.push_back("Gris");
  colores.push_back("Amarillo");
  colores.push_back("Rojo");
  colores.push_back("Negro");
  colores.push_back("Verde");
  colores.push_back("Azul");

  std::vector<std::string> argumentos;

  int i = 0;
  

  do {
    Jugador auxJugador;
    auxJugador.FijarId(i+1);

    //Mostrar colores disponibles
    std::cout << "Los siguientes son los colores disponibles: " << std::endl;

    for(coloresIt = colores.begin(); coloresIt != colores.end(); coloresIt++){
      std::cout << "   - " << *coloresIt << std::endl;
    }
    

    std::cout << "Para el jugador con Id '" << i+1 << "' porfavor ingrese el color que desee: ";
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
      std::cout << "Ingrese solamente el color que desea.\n";
      continue;
    }
    else if (argumentos[0].compare("salir") == 0) {
      return;
    }
    else {
      //Revisar si el color ingresado existe
      bool encontrado = false;

      for (coloresIt = colores.begin(); coloresIt != colores.end(); ) {
        if (argumentos[0].compare(*coloresIt) == 0) {
          encontrado = true;
          coloresIt = colores.erase(coloresIt);
        } else {
          coloresIt++;
        }
    }

      if(encontrado == false){
        std::cout << "Color: '" << argumentos[0] << "' no encontrado o ya fue seleccionado. Porfavor ingrese un color valido. \n";
        continue;
      }
      else{
        auxJugador.FijarColor(argumentos[0]);
        jugadoresPartida.push(auxJugador);
        i++;
      }
    }
  }
  while(i!=cantidad_jugadores);

  //Se empieza con la creacion de todo relacionado con la partida
  //Previamente se agrego el nombre
  //Previamente se agrego tipo partida
  mipartida.FijarsetsTradeados(0);
  mipartida.FijarJugadores(jugadoresPartida); //Se agregan jugadores a la partida

  //Se crean los paises

  //America del Norte
  std::vector<Pais> paisesAmericaDelNorte;
  Pais paisAux;

  paisAux.FijarNombre("Alaska");
  paisesAmericaDelNorte.push_back(paisAux);

  paisAux.FijarNombre("Alberta");
  paisesAmericaDelNorte.push_back(paisAux);

  paisAux.FijarNombre("America Central");
  paisesAmericaDelNorte.push_back(paisAux);

  paisAux.FijarNombre("Estados Unidos Orientales");
  paisesAmericaDelNorte.push_back(paisAux);

  paisAux.FijarNombre("Groenlandia");
  paisesAmericaDelNorte.push_back(paisAux);

  paisAux.FijarNombre("Territorio Noroccidental");
  paisesAmericaDelNorte.push_back(paisAux);

  paisAux.FijarNombre("Ontario");
  paisesAmericaDelNorte.push_back(paisAux);

  paisAux.FijarNombre("Quebec");
  paisesAmericaDelNorte.push_back(paisAux);

  paisAux.FijarNombre("Estados Unidos Occidentales");
  paisesAmericaDelNorte.push_back(paisAux);

  std::cout<< "Paises de Amerrica del Norte creados\n";
  //Recorre los paises de America del Norte y muestra el nombre de cada uno
  //std::vector<Pais>::iterator paisesIt;
  //for (paisesIt = paisesAmericaDelNorte.begin(); paisesIt != paisesAmericaDelNorte.end(); paisesIt++) {
  //  std::cout << "   - " << paisesIt->ObtenerNombre() << std::endl;
  //}

  //America del Sur
  std::vector<Pais> paisesAmericaDelSur;

  paisAux.FijarNombre("Argentina");
  paisesAmericaDelSur.push_back(paisAux);

  paisAux.FijarNombre("Brasil");
  paisesAmericaDelSur.push_back(paisAux);

  paisAux.FijarNombre("Peru");
  paisesAmericaDelSur.push_back(paisAux);

  paisAux.FijarNombre("Venezuela");
  paisesAmericaDelSur.push_back(paisAux);

  std::cout<< "Paises de America del Sur\n";
  //Recorre los paises de America del Sur y muestra el nombre de cada uno
  //for (paisesIt = paisesAmericaDelSur.begin(); paisesIt != paisesAmericaDelSur.end(); paisesIt++) {
  //  std::cout << "   - " << paisesIt->ObtenerNombre() << std::endl;
  //}

  //Europa
  std::vector<Pais> paisesEuropa;

  paisAux.FijarNombre("Gran Bretana");
  paisesEuropa.push_back(paisAux);

  paisAux.FijarNombre("Islandia");
  paisesEuropa.push_back(paisAux);

  paisAux.FijarNombre("Europa del Norte");
  paisesEuropa.push_back(paisAux);

  paisAux.FijarNombre("Escandinavia");
  paisesEuropa.push_back(paisAux);

  paisAux.FijarNombre("Europa del Sur");
  paisesEuropa.push_back(paisAux);

  paisAux.FijarNombre("Ucrania");
  paisesEuropa.push_back(paisAux);

  paisAux.FijarNombre("Europa Occidental");
  paisesEuropa.push_back(paisAux);

  std::cout<< "Paises de Europa\n";
  //Recorre los paises de Europa y muestra el nombre de cada uno
  //for (paisesIt = paisesEuropa.begin(); paisesIt != paisesEuropa.end(); paisesIt++) {
  //  std::cout << "   - " << paisesIt->ObtenerNombre() << std::endl;
  //}

  //Africa
  std::vector<Pais> paisesAfrica;

  paisAux.FijarNombre("Congo");
  paisesAfrica.push_back(paisAux);

  paisAux.FijarNombre("Africa Oriental");
  paisesAfrica.push_back(paisAux);

  paisAux.FijarNombre("Egipto");
  paisesAfrica.push_back(paisAux);

  paisAux.FijarNombre("Madagascar");
  paisesAfrica.push_back(paisAux);

  paisAux.FijarNombre("Africa del Norte");
  paisesAfrica.push_back(paisAux);

  paisAux.FijarNombre("Africa del Sur");
  paisesAfrica.push_back(paisAux);

  std::cout<< "Paises de Africa\n";
  //Recorre los paises de Africa y muestra el nombre de cada uno
  //for (paisesIt = paisesAfrica.begin(); paisesIt != paisesAfrica.end(); paisesIt++) {
  //  std::cout << "   - " << paisesIt->ObtenerNombre() << std::endl;
  //}

  //Asia
  std::vector<Pais> paisesAsia;

  paisAux.FijarNombre("Afghanistan");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("China");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("India");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("Irkutsk");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("Japon");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("Kamchatka");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("Medio Oriente");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("Mongolia");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("Siam");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("Siberia");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("Ural");
  paisesAsia.push_back(paisAux);

  paisAux.FijarNombre("Yakutsk");
  paisesAsia.push_back(paisAux);

  std::cout<< "Paises de Asia\n";
  //Recorre los paises de Asia y muestra el nombre de cada uno
  //for (paisesIt = paisesAsia.begin(); paisesIt != paisesAsia.end(); paisesIt++) {
  //  std::cout << "   - " << paisesIt->ObtenerNombre() << std::endl;
  //}

  //Australia
  std::vector<Pais> paisesAustralia;

  paisAux.FijarNombre("Australia Oriental");
  paisesAustralia.push_back(paisAux);

  paisAux.FijarNombre("Indonesia");
  paisesAustralia.push_back(paisAux);

  paisAux.FijarNombre("Nueva Guinea");
  paisesAustralia.push_back(paisAux);

  paisAux.FijarNombre("Australia Occidental");
  paisesAustralia.push_back(paisAux);

  std::cout<< "Paises de Australia\n";
  //Recorre los paises de Australia y muestra el nombre de cada uno
  //for (paisesIt = paisesAustralia.begin(); paisesIt != paisesAustralia.end(); paisesIt++) {
  //  std::cout << "   - " << paisesIt->ObtenerNombre() << std::endl;
  //}

  //Se crean los continentes
  Continente auxContinente;

  std::vector<Continente> continentes;

  auxContinente.FijarNombre("America del Norte");
  auxContinente.FijarPaises(paisesAmericaDelNorte);
  continentes.push_back(auxContinente);

  auxContinente.FijarNombre("America del Sur");
  auxContinente.FijarPaises(paisesAmericaDelSur);
  continentes.push_back(auxContinente);

  auxContinente.FijarNombre("Europa");
  auxContinente.FijarPaises(paisesEuropa);
  continentes.push_back(auxContinente);

  auxContinente.FijarNombre("Africa");
  auxContinente.FijarPaises(paisesAfrica);
  continentes.push_back(auxContinente);

  auxContinente.FijarNombre("Asia");
  auxContinente.FijarPaises(paisesAsia);
  continentes.push_back(auxContinente);

  auxContinente.FijarNombre("Australia");
  auxContinente.FijarPaises(paisesAustralia);
  continentes.push_back(auxContinente);


  //Esto de aca solo muestra el nombre del continente, cuando se intenta imprimir el pais empieza a dar error,
  //std::vector<Continente>::iterator continentesIt = continentes.begin();
  //for(continentesIt = continentes.begin(); continentesIt != continentes.end(); continentesIt++){
  //    std::cout << "Continente: " << continentesIt->ObtenerNombre() << std::endl;
  //  }

  mipartida.FijarContinentes(continentes);

  //DIEGO
  std::vector<Continente> partidaContinentes = mipartida.ObtenerContinentes();
  std::vector<Continente>::iterator continentIt = partidaContinentes.begin();


  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //Pone la consola en rojo
  std::cout <<std::endl<<std::setw(20) <<"Continente" <<std::setw(30) <<"Pais" <<std::setw(30) <<"Cantidad de tropas"<< std::endl << std::endl;

  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY); //Pone la consola en azul
  for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
    std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
    std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

    for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
      std::cout <<std::setw(20) <<continentIt->ObtenerNombre() <<std::setw(30) <<partidaPaisIt->ObtenerNombre() <<std::setw(30) << partidaPaisIt->ObtenerCantidadTropas() << std::endl;
    }
  }
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); //Pone el color de la consola normal, (la combinacion de rojo verde y azul es blanco)

  //TODO 1: Mostrar el nombre del continente y los paises que tiene desde la clase partida. (HECHO)
  //TODO 2: Crear cartas, dados. 
  //TODO 3: Asignar paises (aleatoriamente), cartas (aleatoriamente) y tropas a jugadores.
  //TODO 4: Arreglar espacio al poner nombre de partida.
  //TODO 5: Clases implementadas con el main 

  std::cout << " Inicializar partida nueva (En construccion).\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

//Mediante esta función se vuelve cargar un juego que ya exista previamente
void Menu::comando_inicializar_existente(const std::string& comando) {
  std::cout << " Inicializar partida existente (En construccion).\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

//La siguiente función tiene como fin realizar el turno de cada jugador con su ataque, defensa y reorganización pertinente
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
    std::cout << "# ";
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
        std::cout << "Error. Por favor ingrese la cantidad de territorios. \n";
      }
    }
  }
  while(!continuar);

  continuar = false;
  
  for (int i = 0; i < canti_territorios; i++) {
    std::string nombre_territorio;
    std::cout << " En cual territorio desea colocar tropas?\n";
    do {  
      std::cout << "# ";      
      do {
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
        }else if(argumentos.size() > 1) {
          std::cout << "Ingrese solamente el nombre del territorio en donde desea colocar tropas\n";
          continue;
        }
        //Regresa al menu principal
        else if (argumentos[0].compare("salir") == 0) {
          std::cout << "Turno abortado. \n";
            return;
        }else {
          nombre_territorio = argumentos[0];
          continuar = true;
        }
      }
      while(!continuar);
      continuar = false;
      for (int j = 0; j < num_territorios; j++) {
        if (nombre_territorio == territorios[j]) {
          territorio_valido = true;
          if(canti_territorios==1){
            std::cout<< " Se han agregado las 7 tropas a "<<nombre_territorio<<"\n";
          }else{
             do {
              std::cout << " Cuantas tropas desea colocar en " << nombre_territorio << "\n";
              std::cout << "# ";
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
          std::cout << " Esta mal escrito por favor vuevalo a escribir\n";
          std::cout << " Recuerde que actualmente tiene estos territorios:\n";
          for(int i=0;i<num_territorios;i++){
            std::cout<<"   -"<<territorios[i]<<"\n";
          }
          }   
    }while (!territorio_valido);
  }
  std::cout << " --------CONFIGURACION DE ATAQUE--------\n";
  std::cout << " Desde cual territorio desea atacar?\n";
  std::cout << " Recuerde que tiene los siguientes territorios: \n";
  for(int i=0;i<num_territorios;i++){
    std::cout<<"   -"<<territorios[i]<<"\n";
  }
    do {
      std::cout << "# ";
      do {
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
      std::cout << "  Por favor ingrese de nuevo el nombre del territorio\n";
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
        std::cout << "# ";
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
      std::cout << "  No existe, por favor ingrese de nuevo el nombre del territorio para atacar\n";
    }
  } while (!territorio_valido_ataque);
  do {
    std::cout << "  Cuantas tropas tiene para atacar?: \n";
    //std::cin >> tropas_atacante;

    do {
      std::cout << "# ";
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
      std::cout << "# ";
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
    
    std::cout << "  Elija una opcion: \n";

    do {
      std::cout << "# ";
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
        std::cout << "  Cuantos dados desea lanzar el atacante (1, 2 o 3)?: \n";
        //std::cin >> num_dados_atacante;

        do {
          std::cout << "# ";
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
        std::cout << "  Cuantos dados desea lanzar el defensor (1 o 2)?: \n";

        do {
          std::cout << "# ";
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

//Con esta función se guarda la partida
void Menu::comando_guardar(const std::string& nombreArchivo) {
  std::cout << " Dentro del comando 'guardar'.\n";
  std::cout << "  Si el comando fue correcto: La partida ha sido guardada correctamente con el nombre de archivo: '" << nombreArchivo << "'.\n";
  std::cout << "  Si no hay ningun juego inicializado: Esta partida no ha sido inicializada correctamente.\n";
  std::cout << "  Si hubo algun error al guardar: La partida no ha sido guardada correctamente.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

//Mediante la función se guarda un comprimido de lo que se lleve del juego
void Menu::comando_guardar_comprimido(const std::string& nombreArchivo) {
  std::cout << " Dentro del comando 'guardar_comprimido'.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

//La función realiza la opcion del comando de costo conquista
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

//Con la función se ingresa a la opcion de conquista mas barata
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

//Función para en caso de ser necesaria brindar ayuda al usuario 
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

//Se usa para cuando hay muchas cosas en consola, por lo tanto limpia la consola
void Menu::limpiar_consola() {
  //Limpia la consola
  if (system("clear") != 0 && system("cls") != 0) {  
    std::cout<<" Error al reiniciar la consola.\n";
  }
}

//Simplemente es la imagen de inicio del juego
void Menu::imagen_risk(){
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
  std::cout << "                                          &@(                                                                                                         \n";
  std::cout << "                                                                                                                                                      \n";
  std::cout << "                                                              Version 0.1.4                                                                           \n";
  std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

//Es el inicio del programa y se redirreciona dependiendo de la opcion que quiera hacer el usuario
void Menu::interaccion_usuario(){
  std::string input, palabra, comando;
  char delimitador = ' ';
  Menu::limpiar_consola();

  Menu::imagen_risk();

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
        std::cout << "Error: Debe ingresar el numero de turno.\n";
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

// eof - menu.hxx
