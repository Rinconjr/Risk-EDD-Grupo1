**Comando:** 

    guardar <nombre_archivo> 

**Descripcion:** El estado actual del juego es guardado en un archivo de texto plano, se guarda la cantidad de jugadores, nombre de cada jugador, color de cada jugador, paises que ocupa, etc.

**Condiciones:** Debe existir una partida previamente creada.

**Explicación Funcionamiento:** 

Para guardar una partida, es necesario que primero haya una partida activa en el programa, de lo contrarió no se procederá a guardar ningún archivo.
Para generar el archivo, lo primero que se realiza es almacenar toda la información de la partida contenida en una cadena de caracteres en formato json para que pueda ser leído en un futuro por el programa cuando el usuario lo desee, para realizar este proceso, se hace un llamado a la función “partida_a_JSON()” que retorna un string guardada en partidaJSON. 
Para finalizar, se genera un archivo con el nombre que el usuario haya querido darle a este, y con extensión .json, el contenido dentro del archivo es la cadena de caracteres en formato json que se ha creado previamente. Una vez se crea el archivo, se le indica al usuario que este ha sido creado con éxito, de no ser así, se le informa del problema.
La siguiente figura ilustra el proceso de guardar en texto plano en RISK:

![Flujo_Guardar](/Documentacion/Imagenes/Flujo%20Guardar%20Comprimido.png)