## ⚙️ Como funciona

[inicializar](Documentacion/inicializar.md)
[turno](Documentacion/turno.md)
[guadar](Documentacion/guardar.md)
[guardar_comprimido](Documentacion/guardar_comprimido.md)
[costo_conquista](Documentacion/costo_conquista.md)
[conquista_mas_barata](Documentacion/conquista_mas_barata.md)
[clear](Documentacion/clear.md)
[salir](Documentacion/salir.md)

- **inicializar:** Comando: *inicializar <nombre_archivo>*  
    Descripcion: Se inicializa una nueva partida si no se especifica el nombre del archivo de la partida guardada. De especificarse uno se reanuda la partida.
- **turno:** Comando: *turno <id_jugador>*
    Descripcion: Informa al jugador la cantidad de unidades que puede reclamar, para luego asignaralas y en que cantidad. Despues, se encarga de la configuración del ataque desde que territorio y hacia cual, luego informa los valores obtenidos con los dados y la cantidad de unidades que se ganan o se pierden, este proceso se repite hasta que alguno de los territorios se quede sin unidades o hasta que el atacante decida detenerse. Por ultimo, pregunta al jugador los territorios vecinos que desea seleccionar para la fortificación tambien la cantidad de unidades que se traslaradan de uno al otro.
- **guardar:** Comando: *guardar nombre_archivo*      
    Descripcion: El estado actual del juego es guardado en un archivo de texto plano, se guarda la cantidad de jugadores, nombre de cada jugador, color de cada jugador, paises que ocupa, etc.
- **Guardar_comprimido:** Comando: *guardar nombre_archivo*  
    Descripción: el estado del juego actual es guardado en un archivo binario. Se guarda la cantidad de jugadores, nombre de cada jugador, color de cada jugador, paises que ocupa, etc.
- **costo_conquista:** Comando: *costo_conquista <territorio>*
    Descripción: Se calcula el costo y secuencia de territorios a ser conquistados para lograr controlarlo. El territorio donde debe atacar debe ser aquel que el jugador tenga controlado más cerca al dado por el usuario. 
- **conquista_mas_barata:** Comando: *conquista_mas_barata*  
    Descripcion: Calcula la conquista mas barata para el jugador actual de todos los territorios posibles. Es decir, aquel territorio que pueda implicar un menor numero de unidades perdidas.
- **clear:** Comando: *clear*  
    Descripcion: Limpia la consola
- **salir:** Comando: *salir*  
    Descripcion: Termina la ejecución del programa. Toda partida que no se halla guardado se perdera.

---
