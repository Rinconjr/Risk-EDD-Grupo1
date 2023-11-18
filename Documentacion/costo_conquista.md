**Comando:** 

    costo_conquista <territorio>

**Descripción:** Se calcula el costo y secuencia de territorios a ser conquistados para lograr controlarlo. El territorio donde debe atacar debe ser aquel que el jugador tenga controlado más cerca al dado por el usuario.

**Condiciones:** Debe existir una partida previamente creada y se debe ingresar un territorio válido.

**Explicacion funcionamiento**

Para determinar el costo de conquista de un país que se pretende atacar, es importante seguir un procedimiento específico dentro del sistema. Al acceder a la opción de turno, el jugador debe completar obligatoriamente la fase 1 para avanzar a la fase 2, donde se ubica la funcionalidad destinada a calcular el costo de conquista de un país en particular.

Una vez dentro de la sección de costo de conquista, se presentará al jugador una tabla que enumera todos los países disponibles para un ataque potencial. En este punto, se solicitará al usuario ingresar el ID correspondiente al país sobre el cual desea conocer el costo de ataque. Una vez que el usuario haya seleccionado un ID válido de país, se iniciará el algoritmo de Dijkstra para determinar el camino más corto desde cada país del jugador. Finalmente, el programa mostrará el costo de la conquista hacia el país que se desea atacar.


La siguiente figura ilustra el proceso del comando costo conquista:

![Diagrama_flujo_costo_conquista](/Documentacion\Imagenes\Diagrama%20de%20Flujo%20costo%20conquista.png)




