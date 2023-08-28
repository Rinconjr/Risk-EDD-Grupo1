**Comando:**

    inicializar <nombre_archivo>

**Descripcion:** Se inicializa una nueva partida si no se especifica el nombre del archivo de la partida guardada. De especificarse uno se reanuda la partida.

**Condiciones:** El usuario no ingrese un espacio o un vacío.

**Explicacion Funcionamiento:** Para entender mejor cómo es el funcionamiento del comando inicializar, se decidió realizar el siguiente diagrama de flujo.

![Flujo_Inicializar](/Documentacion/Imagenes/Flujo%20Inicializar.png)

Cabe recalcar que el usuario puede escribir **salir** en cualquier momento del flujo de interacción para volver al menú principal si cometió algún error, descartando los cambios realizados.

**El comando inicializar tiene las siguientes fases:**
1. Elegir nombre de la partida.
2. Elegir tipo de partida (Normal o Mision Secreta).
3. Elegir numero de jugadores de la partida.
4. Elegir color de cada uno de los jugadores de la partida.

Una vez aceptada cada uno de estas fases con sus respectivos requisitos, el sistema procedera a asignar los paises a cada jugador. Este proceso se llevará a cabo mediante un funcionamiento automatizado que implica la distribución aleatoria de los países y tropas de manera equitativa por parte del sistema.

Para lograr la distribución aleatoria de los países el sistema primero genera un número aleatorio entre la cantidad de jugadores que hay en la partida, por ejemplo, si hay 4 jugadores, es un número entre el 1 y el 4. Posteriormente, la lógica que se utiliza es tener un vector auxiliar de enteros llamado “vectorJugadoresIguales” el cual tendrá el número de posiciones como tantos jugadores haya en la partida. En este, se va a ir guardando el número aleatorio generado, sin embargo, este solo puede aparecer una vez porque se va a ir asignando de a 4 países a la vez, de forma que el primer número (representado el id de cada jugador) que se genere es quien va a recibir el primer país, el segundo número que salga será quien recibirá el segundo país y de esta forma hasta completar el número de jugadores en la partida.

Para representar esto mejor, se crea el siguiente diagrama el cual es el vector “vectorJugadoresIguales”:

<p align="center">
  <img src="/Documentacion/Imagenes/Inicializar%20Vector%20tras%20encontrar.png" alt="FlujoSistemaDeTurnos">
</p>

En este caso, ya salieron los siguientes números aleatorios: **3,1 y 4.** Cabe mencionar que cada que se encuentre un número y se agregue a este vector, se creará el respectivo país con nombre y continentes ya guardados en otro vector.

Si vuelve a salir el 3, este se rechaza porque este vector se utiliza para asegurar que todos los jugadores tengan igual cantidad de países (en los casos que sea posible). Una vez se genere el valor aleatorio 2, este se agrega al vector.

<p align="center">
  <img src="/Documentacion/Imagenes/Inicializar%20vectorJugadoresIguales.png" alt="FlujoSistemaDeTurnos">
</p>

Una vez se encuentre que el tamaño del vector sea igual al tamaño de jugadores, a este vector se le hará .clear() para volver a iniciar el proceso de selección.