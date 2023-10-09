**Comando:** 

    guardar_comprimido <nombre_archivo> 

**Descripción:** el estado del juego actual es guardado en un archivo binario. Se guarda la cantidad de jugadores, nombre de cada jugador, color de cada jugador, paises que ocupa, etc.

**Condiciones:** Debe existir una partida previamente creada.

**Explicación Funcionamiento:** 

Lo primero que se debe hacer es llamar la función “partida_a_JSON()” la cual devuelve un string con toda la partida en un solo string que se guarda en la variable **partidaJSON** que se utilizará más adelante.

Cabe recalcar que nosotros estamos utilizando el **Árbol de Huffman** para codificar la partida y que sea posible guardarla en un archivo **'.bin'**. Para poder generar este árbol con el cual se hará la codificación, se deben calcular las frecuencias en las cuales aparecen cada símbolo (carácter) de toda la partida.

Esto se hace con un simple for el cual va agregando a un **map<char, int>** la frecuencia en la cual aparece cada carácter en el string **partidaJSON**.

Tras la generación de esta tabla de frecuencias en el map, se procede a crear el Árbol de Huffman simplemente usando el constructor creado que recibe un map de frecuencias. Después de esto, se utiliza la función codificar del Árbol de Huffman que devuelve el string “cifrado” y posteriormente se utiliza la función para guardar en archivo binario.

*Lo que hace la función “codificar” del Árbol de Huffman es lo siguiente:*

- Teniendo en cuenta que el árbol ya fue creado con las frecuencias calculadas previamente, la lógica que se sigue es que por cada carácter en el string de la partida completa se busca el código asociado con una función recursiva que hace un recorrido por profundidad que va buscando cada carácter en el árbol y va construyendo el código.

- Cada vez que baje a la izquierda, le agrega 0 al código de longitud variable y cada que baje a la derecha le agrega 1 al código de longitud variable hasta que encuentre el carácter deseado. 

- Esta cadena de 1 's y 0' s se va construyendo poco a poco hasta que llega al final del JSON.

Tras tener este string codificado, se llama a la función “guardarEnArchivoBinario” que recibe el string codificado, el nombre del archivo en donde se va a guardar y las frecuencias asociadas. En pocas palabras, lo que hace esta función es simplemente escribir en un archivo binario teniendo en cuenta la estructura de un archivo binario que fue proporcionada en el enunciado del proyecto.

La siguiente figura ilustra el proceso de guardar comprimido en Risk:

![Flujo_Guardar_Comprimido](/Documentacion/Imagenes/Flujo%20Guardar%20Comprimido.png)

