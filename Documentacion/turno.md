**Comando:** 

    turno <id_jugador>  

**Descripcion:** Informa al jugador la cantidad de unidades que puede reclamar, para luego asignaralas y en que cantidad. Despues, se encarga de la configuración del ataque desde que territorio y hacia cual, luego informa los valores obtenidos con los dados y la cantidad de unidades que se ganan o se pierden, este proceso se repite hasta que alguno de los territorios se quede sin unidades o hasta que el atacante decida detenerse. Por ultimo, pregunta al jugador los territorios vecinos que desea seleccionar para la fortificación tambien la cantidad de unidades que se traslaradan de uno al otro.

**Condiciones:** El usuario debe indicar el id del jugador del cual quiere usar el turno y a este le debe corresponder el turno.

![ColaJugadores](/Documentacion/Imagenes/Cola%20jugadores.png)
                     Imagen: Cola de jugadores

Primero, se crea una variable tipo Jugador auxiliar para guardar el frente de la cola y utilizar el método ObtenerId() para compararlo con el que llegó como parámetro, si este no coincide, quiere decir que no es turno de ese jugador y se rechaza la petición.

Si el turno de jugador es correcto, se ejecutan las tres fases correspondientes del turno, se hace .pop() de la cola de Jugadores y se hace .push() para agregarlo al final de la cola. La siguiente es la representación visual de esto:

![PopColaJugadores](/Documentacion/Imagenes/Pop%20cola%20jugadores.png)
                    Imagen: Pop cola jugadores

![PushColaJugadores](/Documentacion/Imagenes/Push%20cola%20jugadores.png)
                    Imagen: Push cola de jugadores 

Cada que un jugador sea eliminado de la partida, este se elimina de la cola de jugadores y el único jugador que quede en la cola será el ganador de la partida.

<p align="center">
  <img src="/Documentacion/Imagenes/Jugadores%202%20y%203.png" alt="FlujoSistemaDeTurnos">
</p>
                    Imagen: Jugadores 2 y 3 eliminados

<p align="center">
  <img src="/Documentacion/Imagenes/Jugador 4.png" alt="FlujoSistemaDeTurnos">
</p>
                    Imagen: Jugador 4 ganador

Tras entender cómo funciona el sistema de turnos mediante colas en la partida, para entender mejor el funcionamiento de cada unas de las fases de turno, se decidió realizar el siguiente diagrama de flujo:

![FlujoSistemaDeTurnos](/Documentacion/Imagenes/Flujo%20turno.jpeg)
                    Imagen: Flujo sistema de turnos

- Fase 1 (Obtener nueva unidades): Durante esta fase se le informará al usuario cuantas tropas adicionales puede reclamar, para luego preguntar en cuál(es) de los territorios de su propiedad las quiere asignar y en qué cantidad. Ahora, el sistema tendrá la tarea de calcular la bonificación de las tropas, que este variará dependiendo de la cantidad de territorios que tenga el usuario. Posteriormente se le mostrará un menú al usuario donde podrá ver todos los países, ver sus países, fortificar el país con las tropas de bonificación, canjear cartas, dirigirse a la siguiente fase o salir, es importante resaltar que el usuario no podrá avanzar a la siguiente fase si no ha distribuido las tropas de bonificación anteriormente.

- Fase 2 (Atacar): Durante el transcurso de esta etapa, el usuario dispondrá de la oportunidad de llevar a cabo la configuración de su estrategia ofensiva. En este proceso, podrá seleccionar tanto el punto de origen del ataque como el destino al cual desea dirigirse, teniendo en cuenta que el usuario solo podrá seleccionar este territorio si tiene más de una tropa en este, ya que no está permitido atacar desde un territorio en el que solo exista una tropa. Además, el sistema proporciona un menú de opciones para cada jugador en esta fase, en el cual podrá ejecutar opciones como llevar a cabo ataques, ver sus propios territorios, mostrar los territorios de los otros jugadores y progresar a la siguiente fase del juego. Cabe recalcar que es posible no atacar y simplemente ir a la siguiente fase.

- Fase 3 (Fortificar): En la fase final del turno de comando, el usuario tendrá la oportunidad de fortalecer uno de sus territorios, mediante la selección de la cantidad de tropas que desee movilizar desde un territorio propio hacia el territorio elegido previamente, sin embargo, sólo podrá movilizar tropas si el territorio en cuestión tiene más de una tropa, ya que, no es posible dejar un territorio sin tropas. 



