**Comando:**

    conquista_mas_barata

**Descripcion:** Calcula la conquista mas barata para el jugador actual de todos los territorios posibles. Es decir, aquel territorio que pueda implicar un menor numero de unidades perdidas.

**Condiciones:** Debe existir una partida previamente creada.

**Explicacion funcionamiento**

Para determinar el costo de la conquista más económica disponible para el jugador, se requiere seguir un procedimiento específico. En primer lugar, es fundamental que el usuario se sitúe en la opción de turno correspondiente, específicamente en la segunda fase.

Una vez dentro de la segunda fase del turno, el usuario deberá seleccionar la opción numerada como cinco, lo que permitirá al programa mostrar la conquista que tenga el costo más bajo. El programa obtendrá el ID de todos los países pertenecientes al jugador y los IDs de los países de los demás jugadores para realizar una comparación de tropas entre el jugador y sus vecinos. Finalmente, el programa mostrará la conquista de menor costo disponible.


La siguiente figura ilustra el proceso del comando costo conquista:

![Diagrama de flujo conquista mas barata](/Documentacion/Imagenes/Diagrama%20de%20Flujo%20conquista%20mas%20barata.png)