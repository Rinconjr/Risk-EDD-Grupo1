
# ⚔️🗺 ️Risk 🗺⚔️

![Logo](https://i.ibb.co/cwdJYLQ/deporz7-11d17976-7f29-4185-9285-58b58899a15e.png)

## 📋 Descripcion del proyecto
RISK es originalmente un juego de mesa de estrategia por turnos creado por Hasbro®, que consiste en conquistar territorios a través del mundo. El objetivo es cumplir las misiones del jugador, o alcanzar la supremacia mundial atacando y capturando territorios enemigos.

El juego consta de 42 territorios geográficos a lo largo de todo el mapa, cada uno con un color distinto de acuerdo al continente al que pertenecen, pueden jugar de 2 a 6 personas.

---
## 🎮 Como se juega
El juego comienza con la ocupación de los territorios en donde se distribuyen las tropas de cada jugador en los territorios que se le asignan dadas las cartas que le toquen, el jugador está en la libertad de distribuir sus tropas en los territorios que domina cuando recibe nuevas tropas. 

### Bonificacion
Al inicio de cada turno, el jugador recibe tropas en su ejercto. Las nuevas unidades que recibe se determinan por la cantidad de territorios/continentes/cartas que posea:
- **Territorios: Cada 3 territorios el jugador recibe una tropa adicional.**
- **Continentes: Si el jugador ocupa todos los territorios de un continente, recibe una bonificación de acuerdo a la dificultad del continente:**
    - **America del sur: 2 tropas adicionales**
    - **Oceania: 2 tropas adicionales**
    - **Africa: 3 tropas adicionales**
    - **America del norte: 5 tropas adicionales**
    - **Europa: 5 tropas adicionales**
    - **Asia: 7 tropas adicionales**
- **Cartas:**

Las bonificaciones de un mismo turno son acumulativas.

### Ataques
El jugador puede atacar cualquier territorio siempre y cuando:
- Sea un territorio vecino a uno de los territorios que posee el jugador
- El jugador tenga más de una tropa en su territorio para poder atacar (una tropa siempre debe estar ocupando el territorio y no tiene permitido atacar a otros territorios)

Los resultados de las batallas se deciden al azar, el atacante puede atacar hasta con un máximo de tres tropas simultaneamente, el defensor tambien puede defenderse con tres tropas a la vez hasta que no tenga como defenderse, o cuando el atacante se rinda.

Cuando se logran derrotar todas las tropas de un territorio, el jugador debe moverse al nuevo territorio y reclamarlo.

### Fortificación
Antes de finalizar el turno, el jugador puede mover tropas de territorios siempre y cuando sea por territorios vecinos que el posea.

**Este proceso se repite hasta que un sólo jugador haya tomado control de los 42 territorios del tablero**    

**Si desea mas información sobre las reglas del juego, consulte el manual de risk: ** [Click aqui](https://www.hasbro.com/common/instruct/risk.pdf)

---
## 👀 Características

---
## ⚙️ Como funciona

- **inicializar:** Comando: *inicializar <nombre_archivo>*  
    Descripcion: Se inicializa una nueva partida si no se especifica el nombre del archivo de la partida guardada. De especificarse uno se reanuda la partida.
- **turno:**
- **guardar:** Comando: *guardar nombre_archivo*      
    Descripcion: El estado actual del juego es guardado en un archivo de texto plano, se guarda la cantidad de jugadores, nombre de cada jugador, color de cada jugador, paises que ocupa, etc.
- **Guardar_comprimido:** Comando: *guardar nombre_archivo*  
    Descripción: el estado del juego actual es guardado en un archivo binario. Se guarda la cantidad de jugadores, nombre de cada jugador, color de cada jugador, paises que ocupa, etc.
- **costo_conquista:**
- **conquista_mas_barata:** Comando: *conquista_mas_barata*  
    Descripcion: Calcula la conquista mas barata para el jugador actual de todos los territorios posibles. Es decir, aquel territorio que pueda implicar un menor numero de unidades perdidas.
- **clear:** Comando: *clear*  
    Descripcion: Limpia la consola
- **salir:** Comando: *salir*  
    Descripcion: Termina la ejecución del programa. Toda partida que no se halla guardado se perdera.

---
## Requerimientos
- Sistema operativo Linux o Windows
- Version de C++11

---
## 💻  Compilación y Ejecución
1. Paso 1: Abrir consola o CMD
2. Paso 2: g++ -std=c++11 main.cpp -o risk
3. Paso 3: (Windows): risk.exe
4. Paso 3: (Linux):  ./risk

---
## 💼  Integrantes

- Nicolás Rincón Ballesteros
- Santiago Yañez Barajas
- Juan Diego Echeverry Plazas

---
