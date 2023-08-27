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
#include <algorithm> // Necesario para std::shuffle
#include <random> 

//************************************************************************
// FIN - LIBRERIAS
//************************************************************************

//************************************************************************
// INICIO - VARIABLES GLOBALES
//************************************************************************
Partida mipartida;
//************************************************************************
// FIN - VARIABLES GLOBALES
//************************************************************************

//************************************************************************
// INICIO - FUNCIONES
//************************************************************************

//La función se emplea en situaciones en las cuales el usuario requiere asistencia en relación al funcionamiento de alguno de los comandos. Se procederá a verificar cuál es el comando específico con respecto al cual necesita ayuda, y se le proporcionará la asistencia correspondiente.
void Menu::comando_ayuda_comandos(std::string comando){
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

//Función que verifica si un string contiene solo espacios en blanco
bool Menu::contieneSoloEspacios(std::string str) {
  for (int i = 0; i < str.length(); i++) {
    if (str[i] != ' ') {
      return false;
    }
  }
  return true;
}

//Es la función con la que se inicializa el juego
void Menu::comando_inicializar_nueva_partida() {

  //Variables para almacenar argumentos del usuario
  bool continuar = false;
  char delimitador = ' ';
  std::string cinUsuario, nombre_partida;
  std::vector<std::string> argumentos;

  //Variables para crear vector tipo de tipo string
  std::vector<std::string> vectorString;
  std::vector<std::string>::iterator vectorStringIt;

  //Variables para crear queue jugadores
  int cantidad_jugadores;
  std::queue<Jugador> jugadoresPartida;

  //Variables para crear colores
  std::vector<std::string> colores = {"Gris","Amarillo","Rojo","Negro","Verde","Azul"};
  std::vector<std::string>::iterator coloresIt;

  //Variables para crear paises y cartas
  Carta auxCarta;
  std::vector<Pais> paisesContinente;
  std::vector<Continente> continentes;
  std::vector<Carta> cartas;
  std::string temp = "";

  std::vector<std::string> nombrePaises = {"Alaska","Alberta","America Central","Estados Unidos Orientales","Groenlandia","Territorio Noroccidental","Ontario","Quebec","Estados Unidos Occidentales","Argentina","Brasil","Peru","Venezuela","Gran Bretana","Islandia","Europa del Norte","Escandinavia","Europa del Sur","Ucrania","Europa Occidental","Congo","Africa Oriental","Egipto","Madagascar","Africa del Norte","Africa del Sur","Afghanistan","China","India","Irkutsk","Japon","Kamchatka","Medio Oriente","Mongolia","Siam","Siberia","Ural","Yakutsk","Australia Oriental","Indonesia","Nueva Guinea","Australia Occidental"};
  std::vector<std::string> paisContinente = {"America del Norte","America del Norte","America del Norte","America del Norte","America del Norte","America del Norte","America del Norte","America del Norte","America del Norte","America del Sur","America del Sur","America del Sur","America del Sur","Europa","Europa","Europa","Europa","Europa","Europa","Europa","Africa","Africa","Africa","Africa","Africa","Africa","Asia","Asia","Asia","Asia","Asia","Asia","Asia","Asia","Asia","Asia","Asia","Asia","Australia","Australia","Australia","Australia"};
  std::vector<std::string> tropa =        {"Tropa","Tropa","Caballeria","Artilleria","Caballeria","Artilleria","Artilleria","Artilleria","Tropa","Caballeria","Artilleria","Caballeria","Artilleria","Caballeria","Tropa","Caballeria","Artilleria","Caballeria","Artilleria","Tropa","Caballeria","Artilleria","Tropa","Tropa","Tropa","Artilleria","Tropa","Caballeria","Tropa","Tropa","Tropa","Caballeria","Artilleria","Artilleria","Artilleria","Artilleria","Caballeria","Caballeria","Tropa","Caballeria","Caballeria","Artilleria"};
  std::vector<int> bonificacionContinentes = {4,3,5,3,7,2};

  std::vector<std::string>::iterator nombreIt = nombrePaises.begin();
  std::vector<std::string>::iterator paisIt = paisContinente.begin();
  std::vector<std::string>::iterator tropaIt = tropa.begin();

  //Variables para crear dados
  Dado auxDado;
  std::vector<Dado> dados;

  //Aleatorizar paises
  std::vector<std::string> auxPaises;
  std::vector<std::string> paisesAsignados;

  std::cout << "Se creara una partida nueva.\nSi desea cargar una partida existente, regrese al menu principal escribiendo 'salir' y luego escriba 'inicializar <nombre_archivo>' \n";
  do {
    std::cout << "Ingrese el nombre para la partida: ";
    std::getline(std::cin, cinUsuario);
    std::stringstream stream(cinUsuario);
    argumentos.clear();

    // while para ir guardando los argumentos en el vector
    while (getline(stream, cinUsuario, delimitador)) {
      argumentos.push_back(cinUsuario);    
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
    // Verificamos si el nombre de la partida contiene solo espacios en blanco
    else if (contieneSoloEspacios(argumentos[0])) {
      std::cout << "El nombre de la partida no puede contener solo espacios en blanco. \n";
      continue;
    }
    else {
      nombre_partida = argumentos[0];
      continuar = true;
    }
  }
  while(!continuar);

  //Guardar el nombre de la partida
  mipartida.FijarNombre(nombre_partida);

  std::cout << "Recuerde que si desea volver al menu principal en cualquier momento escribiendo: 'salir'. \n";

  //Agregar colores de la partida
  vectorString.push_back("MisionSecreta");
  vectorString.push_back("Normal");

  continuar = false;

  //Mostrar tipos de partida disponibles
  std::cout << "Los siguientes son los tipos de partida disponibles: " << std::endl;

  for(vectorStringIt = vectorString.begin(); vectorStringIt != vectorString.end(); vectorStringIt++){
    std::cout << "   - " << *vectorStringIt << std::endl;
  }

  //Preguntar el tipo de la partida
  do {
    std::cout << "Que tipo de partida desea crear para '"<< nombre_partida <<"': ";
    std::getline(std::cin, cinUsuario);
    std::stringstream stream(cinUsuario);
    argumentos.clear();

    // while para ir guardando los argumentos en el vector
    while (getline(stream, cinUsuario, delimitador)) {
      argumentos.push_back(cinUsuario);    
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

      for(vectorStringIt = vectorString.begin(); vectorStringIt != vectorString.end(); vectorStringIt++){
        if(argumentos[0].compare(*vectorStringIt) == 0){
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
    std::cout << "Cuantos jugadores tendra la partida '" << nombre_partida << "' (Min 3, Max 6): ";
    std::getline(std::cin, cinUsuario);
    std::stringstream stream(cinUsuario);
    argumentos.clear();

    // while para ir guardando los argumentos en el vector
    while (getline(stream, cinUsuario, delimitador)) {
      argumentos.push_back(cinUsuario);    
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
        
        if (cantidad_jugadores >= 3 && cantidad_jugadores <= 6) {
          continuar = true;
        } 
        else {
          std::cout << "Error. Debe ingresar entre 3 a 6 jugadores. \n";
        }
      } 
      catch (const std::invalid_argument&) {
        std::cout << "Error. Debe ingresar el numero de jugadores para la partida. \n";
      }
    }
  }
  while(!continuar);

  int i = 0;
  
  //Preguntar por colores de jugadores
  do {
    Jugador auxJugador;
    auxJugador.FijarId(i+1);

    //Mostrar colores disponibles
    std::cout << "Los siguientes son los colores disponibles: " << std::endl;

    for(coloresIt = colores.begin(); coloresIt != colores.end(); coloresIt++){
      std::cout << "   - " << *coloresIt << std::endl;
    }

    std::cout << "Para el jugador con Id '" << i+1 << "' porfavor ingrese el color que desee: ";
    std::getline(std::cin, cinUsuario);
    std::stringstream stream(cinUsuario);
    argumentos.clear();

    // while para ir guardando los argumentos en el vector
    while (getline(stream, cinUsuario, delimitador)) {
      argumentos.push_back(cinUsuario);    
    }
    // Si no ingreso nada, simplemente continua.
    if (argumentos.empty()) {
      continue;
    }
    else if(argumentos.size() > 1) {
      std::cout << "Ingrese solamente el color que desea.\n";
      std::cout << "Presione enter para continuar.";
      std::cin.ignore();
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
        std::cout << "Presione enter para continuar.";
        std::cin.ignore();
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

  //Crear Paises
  srand(time(0));

  int paisesTotal = 42;
  int tropas_pais = paisesTotal / cantidad_jugadores;
  int dividirPaises = paisesTotal % cantidad_jugadores;

  if (dividirPaises == 0) {
    std::cout << "\n  Se dara la misma cantidad de paises a cada jugador\n";
  } else {
    std::cout << "\n  Al tener " << cantidad_jugadores << " jugadores, dos de los jugadores tendran un pais extra\n";
  }

   if (cantidad_jugadores == 3) {
    tropas_pais = 14;
  } else if (cantidad_jugadores == 4) {
    tropas_pais = 10;
  } else if (cantidad_jugadores == 5) {
    tropas_pais = 8;
  } else if (cantidad_jugadores == 6) {
    tropas_pais = 7;
  }

  std::vector<int> vectorJugadoresIguales;
  for(nombreIt = nombrePaises.begin(); nombreIt != nombrePaises.end(); nombreIt++,paisIt++){
    bool t = true;
    int numeroAleatorio;
    while(t) {
      numeroAleatorio = (rand() % cantidad_jugadores);

      bool tr = false;
      for (int i = 0; i < vectorJugadoresIguales.size(); ++i) {
        if(vectorJugadoresIguales[i] == numeroAleatorio) {
          tr = true;
        }
      }
      if(!tr) {
        vectorJugadoresIguales.push_back(numeroAleatorio);
        t = false;
      }

      if(vectorJugadoresIguales.size() == cantidad_jugadores) {
        vectorJugadoresIguales.clear();
      }
    }
    numeroAleatorio += 1;
    Pais paisAux;
    if(temp != *paisIt || nombreIt == nombrePaises.end() - 1) {
      if(nombreIt == nombrePaises.end() -1){
        paisAux.FijarNombre(*nombreIt);
        paisAux.FijarDueno(numeroAleatorio);
        paisesContinente.push_back(paisAux);
      }
      Continente auxContinente;
      auxContinente.FijarNombre(temp);
      auxContinente.FijarPaises(paisesContinente);
      continentes.push_back(auxContinente);
      paisesContinente.clear();
      temp = *paisIt;
    }
    paisAux.FijarNombre(*nombreIt);
    paisAux.FijarDueno(numeroAleatorio);
    paisesContinente.push_back(paisAux);
  }

  continentes.erase(continentes.begin());
  std::vector<Continente>::iterator continentIt = continentes.begin();
  

  int contadorBonificacion = 0;
  for(continentIt = continentes.begin(); continentIt != continentes.end(); continentIt++){
    continentIt->FijarBonificacion(bonificacionContinentes[contadorBonificacion]);
    contadorBonificacion++;
  }

  //Asignacion de tropas a territorios:
  int tropasPorJugador;

  if(cantidad_jugadores == 3) {
    tropasPorJugador = (35 - tropas_pais);
  }
  else if(cantidad_jugadores == 4) {
    tropasPorJugador = (30 - tropas_pais);
  }
  else if(cantidad_jugadores == 5) {
    tropasPorJugador = (25 - tropas_pais);
  }
  else {
    tropasPorJugador = (20 - tropas_pais);
  }

  for(int i = 0; i < cantidad_jugadores; i++) {
    for(int e = 0; e < tropasPorJugador; e++) {

      int numeroAleatorio = (rand() % tropas_pais);
      int contador = 0;
      std::vector<Continente>::iterator continentIt = continentes.begin();

      for(continentIt = continentes.begin(); continentIt != continentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          if(partidaPaisIt->ObtenerDueno() == i+1) {
            if(contador == numeroAleatorio) {
              partidaPaisIt->FijarCantidadTropas(partidaPaisIt->ObtenerCantidadTropas()+1);
              continentIt->FijarPaises(partidaPais);
            }
            contador++;
          }
          
        }
      }
    }
  }
  mipartida.FijarContinentes(continentes);

  nombreIt = nombrePaises.begin();

  //Cartas normales
  for(nombreIt = nombrePaises.begin(); nombreIt != nombrePaises.end(); nombreIt++,tropaIt++){
    auxCarta.FijarTipo("Normal");
    auxCarta.FijarPais(*nombreIt);
    auxCarta.FijarTropa(*tropaIt);
    cartas.push_back(auxCarta);
  }

  //Cartas comodin
  for(int i = 0; i < 3; i++) {
    auxCarta.FijarTipo("Comodin");
    auxCarta.FijarPais("");
    auxCarta.FijarTropa("");
    cartas.push_back(auxCarta);
  }

  mipartida.FijarCartas(cartas);

  //Dados
  for(int i = 0; i < 3; i++) {
    auxDado.FijarColor("Ataque");
    dados.push_back(auxDado);
  }

  for(int i = 0; i < 2; i++) {
    auxDado.FijarColor("Defensa");
    dados.push_back(auxDado);
  }

  mipartida.FijarDados(dados);

  //Mostrar continentes y paises creados con su respectivo dueño y cantidad de tropas
  std::cout << "  Se crearon los siguientes continentes y paises: \n";
  std::vector<Continente> partidaContinentes = mipartida.ObtenerContinentes();
  continentIt = partidaContinentes.begin(); 

  partidaContinentes = mipartida.ObtenerContinentes();
  continentIt = partidaContinentes.begin();

  int inventario = 1;

  std::cout << std::endl << std::setw(20) << "Continentes" << std::setw(30) << "Pais" << std::setw(30) << "Cantidad de tropas" << std::setw(30) << "Dueno" << std::endl << std::endl;

  int contador[cantidad_jugadores];
  for(int i = 0; i < cantidad_jugadores; i++) {
    contador[i] = 0;
  }
  for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
    std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
    std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

    for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
      contador[partidaPaisIt->ObtenerDueno() -1] += 1;
      std::cout << std::setw(2) << inventario << ") " << std::setw(20) << continentIt->ObtenerNombre() << std::setw(30) << partidaPaisIt->ObtenerNombre() << std::setw(25) << partidaPaisIt->ObtenerCantidadTropas() << std::setw(30) << partidaPaisIt->ObtenerDueno()<< std::endl;
      inventario++;
    }
  }
  std::cout << std::endl << "Cantidad de paises por jugador: " << std::endl;
  for(int i = 0; i < cantidad_jugadores; i++) {
    std::cout << "Jugador " << i+1 << ": " << contador[i] << std::endl;
  }

  std::cout << "\n Partida creada exitosamente.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

//Mediante esta función se vuelve cargar un juego que ya exista previamente
void Menu::comando_inicializar_existente(std::string comando) {
  std::cout << " Inicializar partida existente (En construccion).\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

//La siguiente función tiene como fin realizar el turno de cada jugador con su ataque, defensa y reorganización pertinente
void Menu::comando_turno(std::string comando) {
  std::vector<std::string> argumentos;
  char delimitador = ' ';
  std::string cinUsuario;
  int inventario = 1;
  bool continuar = false;
  int turnoJugador = std::stoi(comando);
  std::string continenteDominado = "";
  bool conquistoPais = false;
  std::string paisAtaque, paisDefensor;
  int duenoPaisDefensor;

  //Obtiene los jugadores de la partida
  std::queue<Jugador> jugadores = mipartida.ObtenerJugadores();
  Jugador jugadorTurno = jugadores.front();


  std::vector<Continente> partidaContinentes = mipartida.ObtenerContinentes();
  std::vector<Continente>::iterator continentIt = partidaContinentes.begin(); 

  //Comprobar que hay una partida cargada
  if(mipartida.ObtenerNombre() == "") {
    std::cout << " No se ha cargado o inicializado una partida. \n";
    std::cout << " Presione enter para continuar.";
    std::cin.ignore();
    return;
  }
  //Comprobar que está jugando el jugador al que le toca jugar
  else if(jugadorTurno.ObtenerId() != turnoJugador) {
    std::cout << " No es puede continuar con el turno. El jugador "<< jugadorTurno.ObtenerId() << " es a quien le toca jugar" << std::endl;
    std::cout << " Presione enter para continuar.";
    std::cin.ignore();
    return;
  }

  //Calcular tropas
  int sumarTropas = 0; //TODO: Esto esta mal, se debe dividir el numero de territorios que ocupa el jugador entre 3 y esas son las tropas en cada turno.
  std::vector<Pais> paisesJugador;

  //Si domina un continente se le suman las tropas de bonificacion
  partidaContinentes = mipartida.ObtenerContinentes();
  continentIt = partidaContinentes.begin();

  for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
    bool domina = true;
    std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
    std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

    for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
      if(partidaPaisIt->ObtenerDueno() != turnoJugador) {
        domina = false;
      }
      else {
        sumarTropas++;
        paisesJugador.push_back(*partidaPaisIt);
      }
    }

    if(domina) {
      sumarTropas += continentIt->ObtenerBonificacion();
      continenteDominado = continentIt->ObtenerNombre(); //Se guarda el nombre del continente dominado
    }
  }
  sumarTropas = sumarTropas / 3;
  if(sumarTropas < 3) {
    sumarTropas = 3;
  }

  //FASE 1
  int opcion3Seleccionada = 0;
  char posibilidad_salir;
  while(!continuar) {
    std::cout<<"\n---------------------MENU TURNO-------------------------\n";
    std::cout << "Turno del jugador " << turnoJugador <<"\n";

    if(continenteDominado.empty() == false){
      std::cout << "Usted tiene una bonificacion de tropas por dominar el continente '" << continenteDominado << "'." << std::endl;
    }
    

    std::cout << "Fase 1" << std::endl << std::setw(30) << "Opciones\n";
    std::cout << "1) Ver todos los paises.\n";
    std::cout << "2) Ver mis paises.\n";
    if (sumarTropas != 0){
      std::cout << "3) Fortificar pais. Usted tiene " << sumarTropas << " tropas por asignar!!!\n";
    }
    else{
      std::cout << "3) Fortificar pais. IMPORTANTE: Es posible avanzar de fase! Ya asigno las tropas.\n";
    }
    std::cout << "4) Canjear cartas.\n";
    std::cout << "5) Siguiente fase.\n";
    std::cout << "6) Salir.\n";
    std::cout<<"---------------------MENU TURNO-------------------------\n";

    do {
      continuar = false;

      std::cout << "Seleccione el numero de la opcion: ";
      std::getline(std::cin, cinUsuario);
      std::stringstream stream(cinUsuario);
      argumentos.clear();

      // while para ir guardando los argumentos en el vector
      while (getline(stream, cinUsuario, delimitador)) {
        argumentos.push_back(cinUsuario);    
      }
      // Si no ingreso nada, simplemente continua.
      if (argumentos.empty()) {
        continue;
      }
      // Verificamos si el nombre de la partida contiene solo espacios en blanco
      else if (contieneSoloEspacios(argumentos[0])) {
        std::cout << "Porfavor ingrese una opcion. \n";
        continue;
      }
      else {
        cinUsuario = argumentos[0];
        continuar = true;
      }
    }
    while(!continuar);
    continuar = false;

    //Se muestran todos los paises de la partida
    if(cinUsuario == "1") {
      partidaContinentes = mipartida.ObtenerContinentes();
      continentIt = partidaContinentes.begin();

      inventario = 1;

      std::cout<<"\n----------------------------------------------PAISES PARTIDA--------------------------------------------------";
      std::cout << std::endl << std::setw(20) << "Continentes" << std::setw(30) << "Pais" << std::setw(30) << "Cantidad de tropas" << std::setw(30) << "Dueno" << std::endl;

      for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          std::cout << std::setw(2) << inventario << ") " << std::setw(20) << continentIt->ObtenerNombre() << std::setw(30) << partidaPaisIt->ObtenerNombre() << std::setw(25) << partidaPaisIt->ObtenerCantidadTropas() << std::setw(30) << partidaPaisIt->ObtenerDueno()<< std::endl;
          inventario++;
        }
      }
      std::cout<<"----------------------------------------------PAISES PARTIDA--------------------------------------------------\n\n";
    }
    //Se muestran los paises del jugador
    else if(cinUsuario == "2") {
      partidaContinentes = mipartida.ObtenerContinentes();
      continentIt = partidaContinentes.begin();

      inventario = 1;

      std::cout<<"\n------------------------------PAISES JUGADOR " << turnoJugador << "----------------------------------";
      std::cout << std::endl << std::setw(20) << "Continentes" << std::setw(30) << "Pais" << std::setw(30) << "Cantidad de tropas" << std::endl;

      for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          if(partidaPaisIt->ObtenerDueno() == turnoJugador ) {
            std::cout << std::setw(2) << inventario << ") " << std::setw(20) << continentIt->ObtenerNombre() << std::setw(30) << partidaPaisIt->ObtenerNombre() << std::setw(25) << partidaPaisIt->ObtenerCantidadTropas() << std::endl;
            inventario++;
          }
        }
      }
      std::cout<<"------------------------------PAISES JUGADOR " << turnoJugador << "---------------------------------\n\n";
    }
    //Se fortifica un pais
    else if(cinUsuario == "3") {
      if(sumarTropas == 0) {  //El jugador no tiene tropas por asignar
        std::cout << "\nNo tienes mas tropas por asignar, canjea cartas o pasa a la siguiente fase.\n";
        std::cout << "Presione enter para continuar. " << std::endl;
        std::cin.ignore();
      }
      else {  //El jugador tiene tropas por asignar
        inventario = 1;
        std::vector<Pais>::iterator paisesJugadorIt = paisesJugador.begin();
        std::cout<<"\n---------------------PAISES JUGADOR " << turnoJugador << "-------------------------\n";
        std::cout <<std::setw(5) << "# Pais" << std::setw(30) << "Nombre del pais" << std::setw(12) << "Tropas del pais" << std::endl;
        for(paisesJugadorIt = paisesJugador.begin(); paisesJugadorIt != paisesJugador.end(); paisesJugadorIt++){
          std::cout <<std::setw(5) << inventario << std::setw(30) << paisesJugadorIt->ObtenerNombre() << std::setw(10) << paisesJugadorIt->ObtenerCantidadTropas() << std::endl;
          inventario++;
        }
        std::cout<<"---------------------PAISES JUGADOR " << turnoJugador << "-------------------------\n\n";
        do {
          int numeroPais, tropasPais, numeroTropas;
          std::string paisFortificar;
          std::cout<<"Seleccione el # del pais que desea fortificar: ";
          std::getline(std::cin, cinUsuario);
          std::stringstream stream(cinUsuario);

          // Si no ingreso nada, simplemente continua.
          if (argumentos.empty()) {
            continue;
          }
        
          try {
            numeroPais = std::stoi(cinUsuario); 
          } 
          catch (const std::invalid_argument& e) {
            std::cout << "Argumento invalido. Debe ingresar el numero del pais. " << std::endl;
            continue;
          }
          
          if(numeroPais > inventario) {
            std::cout << "El pais que estas tratando de seleccionar no te pertenece. " << std::endl;
          }
          else {
            paisesJugadorIt = paisesJugador.begin() + (numeroPais -1);
            paisFortificar = paisesJugadorIt->ObtenerNombre();
            tropasPais = paisesJugadorIt->ObtenerCantidadTropas();
          }

          std::cout << "Puedes anadir " << sumarTropas << " tropas. " << std::endl;
          std::cout << "El pais seleccionado: '" << paisFortificar << "' tiene actualmente " << tropasPais << " tropas. \n";
          do {
            
            std::cout << " Seleccione el numero de tropas que anadira a '" << paisFortificar <<"': ";
            std::getline(std::cin, cinUsuario);
            std::stringstream stream(cinUsuario);
          
            // Si no ingreso nada, simplemente continua.
            if (argumentos.empty()) {
              continue;
            }

            try {
              numeroTropas = std::stoi(cinUsuario); 
            } 
            catch (const std::invalid_argument& e) {
              std::cout << "Argumento invalido. Debe ingresar el numero de tropas." << std::endl;
              continue;
            }

            if(sumarTropas < numeroTropas) {
              std::cout << "No tienes tantas tropas, actualmente tienes "<< sumarTropas << " tropas por asignar." << std::endl;
              continue;
            }
            else if (numeroTropas < 0) {
              std::cout << "No puedes poner tropas negativas. Actualmente tienes "<< sumarTropas << " tropas por asignar. " << std::endl;
              continue;
            }
            else { //Si se ingreso un numero valido de tropas
              partidaContinentes = mipartida.ObtenerContinentes();
              continentIt = partidaContinentes.begin();

            for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
              bool domina = true;
              std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
              std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

              for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
                if(partidaPaisIt->ObtenerNombre() == paisFortificar) {
                  partidaPaisIt->FijarCantidadTropas(partidaPaisIt->ObtenerCantidadTropas() + numeroTropas); //Se agrega la cantidad de tropas al pais
                  continentIt->FijarPaises(partidaPais);
                  mipartida.FijarContinentes(partidaContinentes);
                  sumarTropas -= numeroTropas; //Se restan las tropas asignadas
                  continuar = true;
                  continue;
                }
              }
            }

            std::cout << "\nAgregando tropas a " << paisFortificar << "..." << std::endl;
            std::cout << "Presione enter para continuar. " << std::endl;
            std::cin.ignore();
          }
        }
        while(!continuar);
      }
      while(!continuar);
      continuar = false;
      }
    }
    //Se canjean cartas
    else if(cinUsuario == "4") {
      //Codigo canjear cartas
      inventario = 1;
      std::vector<Carta> cartasJugador = jugadorTurno.ObtenerCartas();
      std::vector<Carta>::iterator cartaIt = cartasJugador.begin();
      std::cout <<std::setw(10) << "# Carta" << std::setw(30) << "Pais" << std::setw(20) << "Tipo Carta" << std::setw(10) << "Tropa" << std::endl;
      for(cartaIt = cartasJugador.begin(); cartaIt != cartasJugador.end(); cartaIt++){
        std::cout <<std::setw(10) << inventario << ")" << std::setw(30) << cartaIt->ObtenerPais() << std::setw(20) << cartaIt->ObtenerTipo() << std::setw(10) << cartaIt->ObtenerTropa() << std::endl;
        inventario++;
      }

    }
    //Seguir de fase
    else if(cinUsuario == "5") {
      if(sumarTropas > 0) {
        std::cout << "\nPara poder seguir de fase, debe asignar todas las tropas. !!Usted aun tiene " << sumarTropas << " tropas por asignar!!" << std::endl;
        std::cout << "Presione enter para continuar. " << std::endl;
        std::cin.ignore();
      }
      else {
        continuar = true;
      }
    }
    //Salir del turno
    else if(cinUsuario == "6") {
      std::cout<<"Esta seguro que desea salir? (Si=s/No=n): ";
      std::getline(std::cin, cinUsuario);
      std::stringstream stream(cinUsuario);
      if(cinUsuario=="n"){
        continue;
      }
      else if(cinUsuario=="s"){
        return;
      }
      else{
      }
    }
    else {
      std::cout << "\nOpcion '" << cinUsuario << "' no encontrada. \n";
    }
  }


  std::cout << "\nCambiando a fase 2: Ataque! " << std::endl;
  std::cout << "Presione enter para continuar. " << std::endl;
  std::cin.ignore();

  bool fase2 = true;

  //FASE 2
  bool sin_tropas=false;
  while (fase2){
    std::cout<<"\n---------------------MENU TURNO-------------------------\n";
    std::cout << "Turno del jugador " << turnoJugador <<"\n";
    std::cout << "Fase 2 - Ataque!" << std::endl << std::setw(30) << "Opciones\n";
    std::cout << "1) Atacar.\n";
    std::cout << "2) Ver mis paises y cantidad de tropas\n";
    std::cout << "3) Ver paises enemigos y cantidad de tropas\n";
    std::cout << "4) Siguiente fase.\n";
    std::cout<<"---------------------MENU TURNO-------------------------\n\n";

    do {
      continuar = false;
      std::cout << "Seleccione el numero de la opcion: ";
      std::getline(std::cin, cinUsuario);
      std::stringstream stream(cinUsuario);
      argumentos.clear();

      // while para ir guardando los argumentos en el vector
      while (getline(stream, cinUsuario, delimitador)) {
        argumentos.push_back(cinUsuario);    
      }
      // Si no ingreso nada, simplemente continua.
      if (argumentos.empty()) {
        continue;
      }
      // Verificamos si el nombre de la partida contiene solo espacios en blanco
      else if (contieneSoloEspacios(argumentos[0])) {
        std::cout << "Porfavor ingrese una opcion. \n";
        continue;
      }else {
        cinUsuario = argumentos[0];
        continuar = true;
      }
    }while(!continuar);
    if(cinUsuario.compare("1") == 0) {

      int idPaisAtaque, idPaisDefensa;
      int tropas_atacante, tropas_defensor;

      //mostrar los paises que le pertenecen al jugador
      partidaContinentes = mipartida.ObtenerContinentes();
      continentIt = partidaContinentes.begin();

      inventario = 1;

      std::cout<<"\n--------------------------------PAISES JUGADOR " << turnoJugador << "---------------------------------";
      std::cout << std::endl << std::setw(20) << "Continentes" << std::setw(30) << "Pais" << std::setw(30) << "Cantidad de tropas" << std::endl;
      for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          if(partidaPaisIt->ObtenerDueno() == turnoJugador ) {
            std::cout << std::setw(2) << inventario << ") " << std::setw(20) << continentIt->ObtenerNombre() << std::setw(30) << partidaPaisIt->ObtenerNombre() << std::setw(25) << partidaPaisIt->ObtenerCantidadTropas() << std::endl;
            inventario++;
          }
        }
      }
      std::cout<<"--------------------------------PAISES JUGADOR " << turnoJugador << "---------------------------------\n\n";

      //Se escoge el pais de ataque
      do {
        continuar = false;

        std::cout << "Seleccione el # del pais desde donde atacara: ";
        std::getline(std::cin, cinUsuario);
        std::stringstream stream(cinUsuario);
        argumentos.clear();

        // while para ir guardando los argumentos en el vector
        while (getline(stream, cinUsuario, delimitador)) {
          argumentos.push_back(cinUsuario);    
        }
        // Si no ingreso nada, simplemente continua.
        if (argumentos.empty()) {
          continue;
        }
        // Verificamos si contiene solo espacios en blanco
        else if (contieneSoloEspacios(argumentos[0])) {
          std::cout << "Porfavor ingrese una opcion. \n";
          continue;
        }
        else {
          cinUsuario = argumentos[0];

          try {
            // Intenta convertir el string a un número entero (int)
            idPaisAtaque = std::stoi(cinUsuario);
          } 
          catch (const std::invalid_argument& e) {
            std::cout << "Input invalido. \n";
            continue;
          }
          if(idPaisAtaque < 0 || idPaisAtaque >= inventario) {
            std::cout << "El pais que elegiste no existe. \n";
            continue;
          }

          inventario = 1;

          partidaContinentes = mipartida.ObtenerContinentes();
          continentIt = partidaContinentes.begin();

          //Busca el pais que especifica el usuario
          for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
            std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
            std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

            for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
              if(partidaPaisIt->ObtenerDueno() == turnoJugador ) {
                if(inventario == idPaisAtaque) {
                  tropas_atacante = partidaPaisIt->ObtenerCantidadTropas();
                  paisAtaque = partidaPaisIt->ObtenerNombre();
                }
                inventario++;
              }
            }
          }

          //Si el pais tiene una sola tropa
          if(tropas_atacante == 1) {
            std::cout << "No puedes atacar desde un pais que tiene una sola tropa. \n";
            continue;
          }

          continuar = true;
        }
      }
      while(!continuar);
      continuar = false;

      partidaContinentes = mipartida.ObtenerContinentes();
      continentIt = partidaContinentes.begin();

      inventario = 1;

      std::cout<<"\n-----------------------PAISES JUGADOR DONDE PUEDE ATACAR-----------------------";
      std::cout << std::endl << std::setw(20) << "Continentes" << std::setw(30) << "Pais" << std::setw(30) << "Cantidad de tropas\n";
      for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          if(partidaPaisIt->ObtenerDueno() != turnoJugador ) {
            std::cout << std::setw(2) << inventario << ") " << std::setw(20) << continentIt->ObtenerNombre() << std::setw(30) << partidaPaisIt->ObtenerNombre() << std::setw(25) << partidaPaisIt->ObtenerCantidadTropas() << std::endl;
            inventario++;
          }
        }
      }
      std::cout<<"-----------------------PAISES JUGADOR DONDE PUEDE ATACAR-----------------------\n\n";

      //Se escoge el pais de defensa
      do {
        continuar = false;

        std::cout << "Seleccione el # del pais que se va a atacar: ";
        std::getline(std::cin, cinUsuario);
        std::stringstream stream(cinUsuario);
        argumentos.clear();

        // while para ir guardando los argumentos en el vector
        while (getline(stream, cinUsuario, delimitador)) {
          argumentos.push_back(cinUsuario);    
        }
        // Si no ingreso nada, simplemente continua.
        if (argumentos.empty()) {
          continue;
        }
        // Verificamos si contiene solo espacios en blanco
        else if (contieneSoloEspacios(argumentos[0])) {
          std::cout << "Porfavor ingrese una opcion. \n";
          continue;
        }
        else {
          cinUsuario = argumentos[0];

          try {
            // Intenta convertir el string a un número entero (int)
            idPaisDefensa = std::stoi(cinUsuario);
          } 
          catch (const std::invalid_argument& e) {
            std::cout << "Input invalido. \n";
            continue;
          }
          if(idPaisDefensa< 0 || idPaisDefensa >= inventario) {
            std::cout << "El pais que elegiste no existe. \n";
            continue;
          }

          inventario = 1;

          partidaContinentes = mipartida.ObtenerContinentes();
          continentIt = partidaContinentes.begin();

          //Busca el pais que especifica el usuario
          for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
            std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
            std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

            for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
              if(partidaPaisIt->ObtenerDueno() != turnoJugador ) {
                if(inventario == idPaisDefensa) {
                  tropas_defensor = partidaPaisIt->ObtenerCantidadTropas();
                  paisDefensor = partidaPaisIt->ObtenerNombre();
                  duenoPaisDefensor = partidaPaisIt->ObtenerDueno();
                }
                inventario++;
              }
            }
          }

          continuar = true;
        }
      }
      while(!continuar);
      continuar = false;

      do {
        std::cout << "Se atacara desde el pais " << paisAtaque << " con " << tropas_atacante << std::endl;
        std::cout << "Se defendera el pais " << paisDefensor << " con " << tropas_defensor << std::endl;
        std::cout << "Avisale al jugador " << duenoPaisDefensor << " que vas a atacar su territorio" << std::endl;

        std::cout << "  Opciones:\n";
        std::cout << "   1. Lanzar dados\n";
        std::cout << "   2. Retirarse\n";

        bool continuar2 = false;
        do {
          std::cout << "Seleccione una opcion: ";
          std::getline(std::cin, cinUsuario);
          std::stringstream stream(cinUsuario);
          argumentos.clear();

          // while para ir guardando los argumentos en el vector
          while (getline(stream, cinUsuario, delimitador)) {
            argumentos.push_back(cinUsuario);    
          }
          // Si no ingreso nada, simplemente continua.
          if (argumentos.empty()) {
            continue;
          }
          // Verificamos si contiene solo espacios en blanco
          else if (contieneSoloEspacios(argumentos[0])) {
            std::cout << "Porfavor ingrese una opcion. \n";
            continue;
          }
          else {
            cinUsuario = argumentos[0];

            try {
              // Intenta convertir el string a un número entero (int)
              std::stoi(cinUsuario);
            } 
            catch (const std::invalid_argument& e) {
              std::cout << "Input invalido. \n";
              continue;
            }
            if(cinUsuario == "1") {
              if(tropas_atacante == 1) {
                std::cout << "No puedes atacar mas con este pais porque se ha quedado sin tropas para el ataque" << std::endl;
                continuar = true;
                continue;
              }

              //Se pone el limite a los dados que se pueden usar para el atacante
              int tropasQueatacan = 3;
              if(tropas_atacante <= 3) {
                tropasQueatacan = tropas_atacante - 1;
              }

              int num_dados_atacante, num_dados_defensor;
              do {
                std::cout << "Tienes " << tropasQueatacan << " tropas para atacar. Con cuantas deseas realizar el ataque:";
                std::getline(std::cin, cinUsuario);
                std::stringstream stream(cinUsuario);
                argumentos.clear();

                // while para ir guardando los argumentos en el vector
                while (getline(stream, cinUsuario, delimitador)) {
                  argumentos.push_back(cinUsuario);    
                }
                // Si no ingreso nada, simplemente continua.
                if (argumentos.empty()) {
                  continue;
                }
                // Verificamos si contiene solo espacios en blanco
                else if (contieneSoloEspacios(argumentos[0])) {
                  std::cout << "Porfavor ingrese una opcion. \n";
                  continue;
                }
                else {
                  cinUsuario = argumentos[0];

                  try {
                    // Intenta convertir el string a un número entero (int)
                    num_dados_atacante = std::stoi(cinUsuario);
                  } 
                  catch (const std::invalid_argument& e) {
                    std::cout << "Input invalido. \n";
                    continue;
                  }
                  if(num_dados_atacante<= 0 || num_dados_atacante > tropasQueatacan) {
                    std::cout << "No puedes lanzar esa cantidad de dados. \n";
                    continue;
                  }
                  else {
                    continuar = true;
                  }
                }
              }
              while (!continuar);
              continuar = false;

              //Se pone el limite a los dados que se pueden usar para el defensor
              int tropasQueDefienden = tropas_defensor;
              if (tropasQueDefienden > 2) {
                tropasQueDefienden = 2;
              }
              do {
                std::cout << "Defensor. Tienes " << tropasQueDefienden << " tropas para defender. Con cuantas deseas defenderte:";
                std::getline(std::cin, cinUsuario);
                std::stringstream stream(cinUsuario);
                argumentos.clear();

                // while para ir guardando los argumentos en el vector
                while (getline(stream, cinUsuario, delimitador)) {
                  argumentos.push_back(cinUsuario);    
                }
                // Si no ingreso nada, simplemente continua.
                if (argumentos.empty()) {
                  continue;
                }
                // Verificamos si contiene solo espacios en blanco
                else if (contieneSoloEspacios(argumentos[0])) {
                  std::cout << "Porfavor ingrese una opcion. \n";
                  continue;
                }
                else {
                  cinUsuario = argumentos[0];

                  try {
                    // Intenta convertir el string a un número entero (int)
                    num_dados_defensor = std::stoi(cinUsuario);
                  } 
                  catch (const std::invalid_argument& e) {
                    std::cout << "Input invalido. \n";
                    continue;
                  }
                  if(num_dados_defensor<= 0 || num_dados_defensor > tropasQueDefienden) {
                    std::cout << "No puedes lanzar esa cantidad de dados. \n";
                    continue;
                  }
                  else {
                    continuar = true;
                  }
                }
              }
              while (!continuar);
              continuar = false;
              
              //Se procede a lanzar los dados

              // Lanzamiento de dado aleatorio para el atacante y el defensor
              int dados_atacante[num_dados_atacante];
              int suma_dados_atacante = 0;
              for (int i = 0; i < num_dados_atacante; i++) {
                dados_atacante[i] = rand() % 6 + 1; // Número aleatorio entre 1 y 6
                suma_dados_atacante += dados_atacante[i]; // Sumar al total de la suma del atacante
              }
              std::sort(dados_atacante, dados_atacante + num_dados_atacante, std::greater<int>());
          
              int dados_defensor[num_dados_defensor];
              int suma_dados_defensor = 0;
              for (int i = 0; i < num_dados_defensor; i++) {
                dados_defensor[i] = rand() % 6 + 1; // Número aleatorio entre 1 y 6
                suma_dados_defensor += dados_defensor[i]; // Sumar al total de la suma del defensor
              }
              std::sort(dados_defensor, dados_defensor + num_dados_defensor, std::greater<int>());
          
              // Mostrar resultados de los dados
              std::cout << "\n  ----------------DADOS----------------\n";
              std::cout << "  Resultados del lanzamiento de dados:\n";
              std::cout << "   -Atacante: ";
              for (int i = 0; i < num_dados_atacante; i++) {
                std::cout << dados_atacante[i] << " ";
              }
              std::cout << "\n";
              std::cout << "   -Defensor: ";
              for (int i = 0; i < num_dados_defensor; i++) {
                std::cout << dados_defensor[i] << " ";
              }
              std::cout << "\n  ----------------DADOS----------------\n";
              std::cout << "\n";
          

              // Comparar los resultados de los dados y descontar tropas
              for (int i = 0; i < std::min(num_dados_atacante, num_dados_defensor); i++) {
                if (dados_atacante[i] > dados_defensor[i]) {
                  tropas_defensor--; //se le resta la tropa al defensor
                } else {
                  tropas_atacante--; //se le resta una tropa al atacante
                }
              }
              std::cout << "  -----------TROPAS RESTANTES----------\n";
              // Mostrar cantidad de tropas restantes después del enfrentamiento
              std::cout << "  Tropas restantes:\n";
              std::cout << "   Atacante: " << tropas_atacante << "\n";
              std::cout << "   Defensor: " << tropas_defensor << "\n";
              std::cout << "  -----------TROPAS RESTANTES----------\n";

              int tropasNuevoPais;
              if (tropas_defensor == 0) {
                conquistoPais = true;
                std::cout << "Has conquistado el territorio." << std::endl; 
                do {
                  std::cout <<"Te quedan " << tropas_atacante << " en " <<paisAtaque << ". Cuantas quieren movilizar a " << paisDefensor << ": ";
                  std::getline(std::cin, cinUsuario);
                  std::stringstream stream(cinUsuario);
                  argumentos.clear();

                  // while para ir guardando los argumentos en el vector
                  while (getline(stream, cinUsuario, delimitador)) {
                    argumentos.push_back(cinUsuario);    
                  }
                  // Si no ingreso nada, simplemente continua.
                  if (argumentos.empty()) {
                    continue;
                  }
                  // Verificamos si contiene solo espacios en blanco
                  else if (contieneSoloEspacios(argumentos[0])) {
                    std::cout << "Porfavor ingrese una opcion. \n";
                    continue;
                  }
                  else {
                    cinUsuario = argumentos[0];

                    try {
                      // Intenta convertir el string a un número entero (int)
                      tropasNuevoPais = std::stoi(cinUsuario);
                    } 
                    catch (const std::invalid_argument& e) {
                      std::cout << "Input invalido. \n";
                      continue;
                    }
                    if(tropasNuevoPais<= 0 || tropasNuevoPais > tropas_atacante-1) {
                      std::cout << "No puedes movilizar ese numero de tropas (minimo 1, maximo " << tropas_atacante - 1 << "). \n";
                      continue;
                    }
                    else {
                      tropas_atacante -= tropasNuevoPais;
                      continuar = true;
                    }
                  }
                }
                while (!continuar);
                continuar = false;
              }

              inventario = 1;
              //Conquista pais
              partidaContinentes = mipartida.ObtenerContinentes();
              continentIt = partidaContinentes.begin();

              //Busca el pais que especifica el usuario
              for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
                std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
                std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

                for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
                  if(partidaPaisIt->ObtenerDueno() == turnoJugador ) {
                    if(inventario == idPaisAtaque) {
                      partidaPaisIt->FijarCantidadTropas(tropas_atacante);
                      continentIt->FijarPaises(partidaPais);
                      mipartida.FijarContinentes(partidaContinentes);
                    }
                    inventario++;
                  }
                }
              }

              inventario = 1;
              //Conquista pais
              partidaContinentes = mipartida.ObtenerContinentes();
              continentIt = partidaContinentes.begin();

              //Busca el pais que especifica el usuario
              for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
                std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
                std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

                for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
                  if(partidaPaisIt->ObtenerDueno() != turnoJugador ) {
                    if(inventario == idPaisDefensa && conquistoPais) {
                      continuar = true;
                      partidaPaisIt->FijarCantidadTropas(tropasNuevoPais);
                      partidaPaisIt->FijarDueno(turnoJugador);
                      continentIt->FijarPaises(partidaPais);
                      mipartida.FijarContinentes(partidaContinentes);
                    }
                    inventario++;
                  }
                }
              }
              

              //Busca si el jugador que perdio el territorio ya no tiene mas territorios
              bool sinPaises = true;
              partidaContinentes = mipartida.ObtenerContinentes();
              continentIt = partidaContinentes.begin();
              for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
                std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
                std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();
                for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
                  if(partidaPaisIt->ObtenerDueno() == duenoPaisDefensor ) {
                    sinPaises = false;
                  }
                }
              }

              if(sinPaises) {
                bool eliminado = false;
                while(!eliminado) {
                  Jugador auxJugador = jugadores.front();
                  if(auxJugador.ObtenerId() == duenoPaisDefensor) {
                    //Las cartas del jugador eliminado pasan al otro jugador
                    

                    //Obtenemos la baraja de ambos
                    std::vector<Carta> baraja = auxJugador.ObtenerCartas();
                    std::vector<Carta> barajaJugadorTurno = jugadorTurno.ObtenerCartas();

                    //Hacemos push de cada carta al ganador
                    for(int i = 0; i < baraja.size(); i++) {
                      barajaJugadorTurno.push_back(baraja[i]);
                    }
                    jugadorTurno.FijarCartas(barajaJugadorTurno);
                    
                    jugadores.pop();
                    eliminado = true;
                    
                  }
                  else {
                    jugadores.pop();
                    jugadores.push(auxJugador);
                    
                  }
                }
                mipartida.FijarJugadores(jugadores);

                //Si solo queda el, termina la partida
                if(jugadores.size() == 1) {
                  std::cout << "El jugador " << turnoJugador << " ha ganado la partida" << std::endl;
                  std::cout << " Presione enter para continuar.";
                  std::cin.ignore();
                  return;
                }

                //Reubicar al jugador
                bool ordenado = false;
                while (!ordenado)
                {
                  Jugador auxJugador = jugadores.front();
                  if(auxJugador.ObtenerId() == duenoPaisDefensor) {
                    ordenado = true;
                  }
                  else {
                    jugadores.pop();
                    jugadores.push(auxJugador);
                  }
                  
                }
                
                //#&
              }
              continuar2 = true;
              std::cout << " Guardando cambios...";
              std::cout << " Presione enter para continuar.";
              std::cin.ignore();
            }
            
            else if (cinUsuario == "2") {
              continuar = true;
              continuar2 = true;
            }
            else {
              std::cout << "No existe la opcion. \n";
              continue;
            }
          }
        }
        while (!continuar2);
      }
      while (!continuar);
      continuar = false;
    }
    else if(cinUsuario.compare("2") == 0) {
      //mostrar los paises que le pertenecen al jugador
      partidaContinentes = mipartida.ObtenerContinentes();
      continentIt = partidaContinentes.begin();

      inventario = 1;

      std::cout<<"\n--------------------------------PAISES JUGADOR " << turnoJugador << "---------------------------------";
      std::cout << std::endl << std::setw(20) << "Continentes" << std::setw(30) << "Pais" << std::setw(30) << "Cantidad de tropas" << std::endl;

      for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          if(partidaPaisIt->ObtenerDueno() == turnoJugador ) {
            std::cout << std::setw(2) << inventario << ") " << std::setw(20) << continentIt->ObtenerNombre() << std::setw(30) << partidaPaisIt->ObtenerNombre() << std::setw(25) << partidaPaisIt->ObtenerCantidadTropas() << std::endl;
            inventario++;
          }
        }
      }
      std::cout<<"--------------------------------PAISES JUGADOR " << turnoJugador << "---------------------------------\n\n";
    }
    else if(cinUsuario.compare("3") == 0) {
      //mostrar los paises que no le pertenecen al jugador (A los que puede Atacar)
      partidaContinentes = mipartida.ObtenerContinentes();
      continentIt = partidaContinentes.begin();

      inventario = 1;

      std::cout<<"\n---------------------------------------------PAISES ENEMIGOS-------------------------------------------------";
      std::cout << std::endl << std::setw(20) << "Continentes" << std::setw(30) << "Pais" << std::setw(30) << "Cantidad de tropas\n";
      for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          if (partidaPaisIt->ObtenerDueno() != turnoJugador) { // Cambia la condición
            std::cout << std::setw(2) << inventario << ") " << std::setw(20) << continentIt->ObtenerNombre() << std::setw(30) << partidaPaisIt->ObtenerNombre() << std::setw(25) << partidaPaisIt->ObtenerCantidadTropas() << std::setw(30) << partidaPaisIt->ObtenerDueno()<< std::endl;
            inventario++;
          }
        }
      }
      std::cout<<"---------------------------------------------PAISES ENEMIGOS-------------------------------------------------\n\n";

    }
    if(cinUsuario.compare("4") == 0) {
      fase2 = false;
    }
  }

  //FASE 3

  bool fase3 = true;

  while (fase3){
    std::cout<<"\n---------------------MENU TURNO-------------------------\n";
    std::cout << "Turno del jugador " << turnoJugador <<"\n";
    std::cout << "Fase 3 - Fortificacion!" << std::endl << std::setw(30) << "Opciones\n";
    std::cout << "1) Fortificar pais.\n";
    std::cout << "2) Terminar turno.\n";
    std::cout<<"---------------------MENU TURNO-------------------------\n";

    do {
      continuar = false;

      std::cout << "Seleccione el numero de la opcion: ";
      std::getline(std::cin, cinUsuario);
      std::stringstream stream(cinUsuario);
      argumentos.clear();

      // while para ir guardando los argumentos en el vector
      while (getline(stream, cinUsuario, delimitador)) {
        argumentos.push_back(cinUsuario);    
      }
      // Si no ingreso nada, simplemente continua.
      if (argumentos.empty()) {
        continue;
      }
      // Verificamos si contiene solo espacios en blanco
      else if (contieneSoloEspacios(argumentos[0])) {
        std::cout << "Porfavor ingrese una opcion. \n";
        continue;
      }
      else {
        cinUsuario = argumentos[0];
        continuar = true;
      }
    }
    while(!continuar);
    continuar = false;

    //Se entra a la opcion de fortificar
    if(cinUsuario.compare("1") == 0) {
      int idPaisOrigen, idPaisDestino, cantidadTropas;
      int tropasOrigen = 1;
      partidaContinentes = mipartida.ObtenerContinentes();
      continentIt = partidaContinentes.begin();

      int inventario = 1;

      std::cout<<"\n---------------------PAISES JUGADOR " << turnoJugador << "-------------------------\n";
      std::cout << std::endl << std::setw(20) << "Continentes" << std::setw(30) << "Pais" << std::setw(30) << "Cantidad de tropas" << std::endl << std::endl;

      for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          if(partidaPaisIt->ObtenerDueno() == turnoJugador ) {
            std::cout << std::setw(2) << inventario << ") " << std::setw(20) << continentIt->ObtenerNombre() << std::setw(30) << partidaPaisIt->ObtenerNombre() << std::setw(25) << partidaPaisIt->ObtenerCantidadTropas() << std::endl;
            inventario++;
          }
        }
      }

      do {
        continuar = false;

        std::cout << "Seleccione el # del pais de origen donde trasladaras las tropas: ";
        std::getline(std::cin, cinUsuario);
        std::stringstream stream(cinUsuario);
        argumentos.clear();

        // while para ir guardando los argumentos en el vector
        while (getline(stream, cinUsuario, delimitador)) {
          argumentos.push_back(cinUsuario);    
        }
        // Si no ingreso nada, simplemente continua.
        if (argumentos.empty()) {
          continue;
        }
        // Verificamos si contiene solo espacios en blanco
        else if (contieneSoloEspacios(argumentos[0])) {
          std::cout << "Porfavor ingrese una opcion. \n";
          continue;
        }
        else {
          cinUsuario = argumentos[0];

          try {
            // Intenta convertir el string a un número entero (int)
            idPaisOrigen = std::stoi(cinUsuario);
          } 
          catch (const std::invalid_argument& e) {
            std::cout << "Input invalido. \n";
            continue;
          }
          if(idPaisOrigen < 0 || idPaisOrigen >= inventario) {
            std::cout << "El pais que elegiste no existe. \n";
            continue;
          }

          inventario = 1;

          partidaContinentes = mipartida.ObtenerContinentes();
          continentIt = partidaContinentes.begin();

          //Busca el pais que especifica el usuario
          for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
            std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
            std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

            for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
              if(partidaPaisIt->ObtenerDueno() == turnoJugador ) {
                if(inventario == idPaisOrigen) {
                  tropasOrigen = partidaPaisIt->ObtenerCantidadTropas();
                }
                inventario++;
              }
            }
          }

          //a
          //Si el pais tiene una sola tropa
          if(tropasOrigen == 1) {
            std::cout << "No puedes trasladar tropas desde un pais que tiene una sola tropa. \n";
            continue;
          }

          continuar = true;
        }
      }
      while(!continuar);
      continuar = false;

      partidaContinentes = mipartida.ObtenerContinentes();
      continentIt = partidaContinentes.begin();

      inventario = 1;

      std::cout<<"\n---------------------PAISES JUGADOR " << turnoJugador << "-------------------------\n";
      std::cout << std::endl << std::setw(20) << "Continentes" << std::setw(30) << "Pais" << std::setw(30) << "Cantidad de tropas" << std::endl << std::endl;

      for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();

        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          if(partidaPaisIt->ObtenerDueno() == turnoJugador ) {
            std::cout << std::setw(2) << inventario << ") " << std::setw(20) << continentIt->ObtenerNombre() << std::setw(30) << partidaPaisIt->ObtenerNombre() << std::setw(25) << partidaPaisIt->ObtenerCantidadTropas() << std::endl;
            inventario++;
          }
        }
      }

      do {
        continuar = false;

        std::cout << "Seleccione el # del pais de destino donde trasladaras las tropas: ";
        std::getline(std::cin, cinUsuario);
        std::stringstream stream(cinUsuario);
        argumentos.clear();

        // while para ir guardando los argumentos en el vector
        while (getline(stream, cinUsuario, delimitador)) {
          argumentos.push_back(cinUsuario);    
        }
        // Si no ingreso nada, simplemente continua.
        if (argumentos.empty()) {
          continue;
        }
        // Verificamos si contiene solo espacios en blanco
        else if (contieneSoloEspacios(argumentos[0])) {
          std::cout << "Porfavor ingrese una opcion. \n";
          continue;
        }
        else {
          cinUsuario = argumentos[0];

          try {
            // Intenta convertir el string a un número entero (int)
            idPaisDestino = std::stoi(cinUsuario);
          } 
          catch (const std::invalid_argument& e) {
            std::cout << "Input invalido. \n";
            continue;
          }
          if(idPaisDestino < 0 || idPaisOrigen >= inventario) {
            std::cout << "El pais que elegiste no existe. \n";
            continue;
          }
          else if(idPaisDestino == idPaisOrigen) {
            std::cout << "No puedes transferir tropas al mismo pais de origen. \n";
            continue;
          }
          continuar = true;
        }
      }
      while(!continuar);
      continuar = false;

      do {
        continuar = false;

        std::cout << "Seleccione el # de tropas que vas a transferir. " << "Se pueden transferir " << tropasOrigen-1 <<" tropas maximo: ";
        std::getline(std::cin, cinUsuario);
        std::stringstream stream(cinUsuario);
        argumentos.clear();

        // while para ir guardando los argumentos en el vector
        while (getline(stream, cinUsuario, delimitador)) {
          argumentos.push_back(cinUsuario);    
        }
        // Si no ingreso nada, simplemente continua.
        if (argumentos.empty()) {
          continue;
        }
        // Verificamos si contiene solo espacios en blanco
        else if (contieneSoloEspacios(argumentos[0])) {
          std::cout << "Porfavor ingrese una opcion. \n";
          continue;
        }
        else {
          cinUsuario = argumentos[0];

          try {
            // Intenta convertir el string a un número entero (int)
            cantidadTropas = std::stoi(cinUsuario);
          } 
          catch (const std::invalid_argument& e) {
            std::cout << "Input invalido. \n";
            continue;
          }
          if(cantidadTropas < 0 || cantidadTropas >= tropasOrigen) {
            std::cout << "No puedes transferir tantas tropas. \n";
            continue;
          }
          continuar = true;
        }
      }
      while(!continuar);
      continuar = false;


      partidaContinentes = mipartida.ObtenerContinentes();
      continentIt = partidaContinentes.begin();

      inventario = 1;

      //Actualizar movilizacion
      for(continentIt = partidaContinentes.begin(); continentIt != partidaContinentes.end(); continentIt++){
        std::vector<Pais> partidaPais = continentIt->ObtenerPaises();
        std::vector<Pais>::iterator partidaPaisIt = partidaPais.begin();
        for(partidaPaisIt = partidaPais.begin(); partidaPaisIt != partidaPais.end(); partidaPaisIt++){
          if(partidaPaisIt->ObtenerDueno() == turnoJugador ) {
            if(idPaisOrigen == inventario) {
              std::cout << "Se quitaran " <<cantidadTropas<< " de " << partidaPaisIt->ObtenerNombre() << std::endl;
              partidaPaisIt->FijarCantidadTropas(partidaPaisIt->ObtenerCantidadTropas() - cantidadTropas);
              continentIt->FijarPaises(partidaPais);
              mipartida.FijarContinentes(partidaContinentes);
            }
            else if(idPaisDestino == inventario) {
              std::cout << "Se anadiran " <<cantidadTropas<< " a " << partidaPaisIt->ObtenerNombre() << std::endl;
              partidaPaisIt->FijarCantidadTropas(partidaPaisIt->ObtenerCantidadTropas() + cantidadTropas);
              continentIt->FijarPaises(partidaPais);
              mipartida.FijarContinentes(partidaContinentes);
            }
            inventario++;
          }
        }
      }
      
      fase3 = false;
    } 
    //Se termina el turno
    else if(cinUsuario.compare("2") == 0) {
      fase3 = false;
    }
    //Opcion no encontrada
    else {
      std::cout << "\nOpcion '" << cinUsuario << "' no encontrada. \n";
    }
  }

  if(conquistoPais) {
    std::vector<Carta> listaCartas = mipartida.ObtenerCartas();

    //Elegir una carta aleatoria y guardarla como carta
    int random = (rand() % listaCartas.size());

    std::vector<Carta>cartasJugador = jugadorTurno.ObtenerCartas();
    cartasJugador.push_back(listaCartas[random]);
    listaCartas.erase(listaCartas.begin() + random);

    jugadorTurno.FijarCartas(cartasJugador);
    mipartida.FijarCartas(listaCartas);

    std::cout << "Has ganado una carta por dominar territorios." << std::endl;
  }

  //termina el turno, se pone al jugador en la cola de la partida y va el siguiente
  jugadores.pop();
  jugadores.push(jugadorTurno);
  mipartida.FijarJugadores(jugadores);

  std::cout << " Turno finalizado. \n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

//Con esta función se guarda la partida
void Menu::comando_guardar(std::string nombreArchivo) {
  std::cout << " Dentro del comando 'guardar'.\n";
  std::cout << "  Si el comando fue correcto: La partida ha sido guardada correctamente con el nombre de archivo: '" << nombreArchivo << "'.\n";
  std::cout << "  Si no hay ningun juego inicializado: Esta partida no ha sido inicializada correctamente.\n";
  std::cout << "  Si hubo algun error al guardar: La partida no ha sido guardada correctamente.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

//Mediante la función se guarda un comprimido de lo que se lleve del juego
void Menu::comando_guardar_comprimido(std::string nombreArchivo) {
  std::cout << " Dentro del comando 'guardar_comprimido'.\n";
  std::cout << " Presione enter para continuar.";
  std::cin.ignore();
}

//La función realiza la opcion del comando de costo conquista
void Menu::comando_costo_conquista(std::string territorio) {
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
  std::cout << "                                                              Version 0.0.7                                                                           \n";
  std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
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
