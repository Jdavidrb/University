/**
 * Parcial Práctico 1.
 * Calificación del código: 3.2/5.0 puntos.
 * Multiplicador de la sustentación: 1.0/1.0 puntos.
 * Calificación total: 3.2 x 1.0 = 3.2 puntos.
 * Comentarios generales:
 * 1. La mayor parte de los problemas presentes en su
 *    solución se deben a la no implementación de los
 *    requerimientos del software. La recomendación en
 *    este caso es siempre leer bien lo que se pide en
 *    el desarrollo de un software.
 *
 * Punto 1.1.
 * Calificación: 0.7/1.0
 * Comentarios:
 * 1. Para este punto solamente se debía codificar los
 *    datos de un único personaje. Haber condificado 3
 *    implica utilizar arreglos, mismos que, para este
 *    parcial, están haciendo un gasto injustificado 
 *    de memoria (-0.3).
 *
 * Punto 1.2.
 * Calificación: 0.8/1.0
 * Comentarios:
 * 1. Buen uso de los arreglos para almacenar los datos
 *    de las cartas.
 * 2. ¿A qué hace referencia el arreglo energia[]? Si 
 *    este contiene los valores de gasto de poder, di-
 *    chos valores están demasiado altos, pues los pun-
 *    tos de poder iniciales del jugador son 3. Lo ante-
 *    rior implica que el jugador no podría usar ningu-
 *    na de las cartas del mini-deck (-0.2).
 *
 * Punto 1.3.
 * Calificación: 1.7/3.0
 * Comentarios:
 * 1. Buen uso del la función rand() para obtener ele-
 *    mentos aleatorios dentro de un rango.
 * 2. Aunque la lógica de batalla funciona, existen al-
 *    gunos problemas en el cumplimiento de los requeri-
 *    mientos, además de posibles problemas de implemen-
 *    tación (-1.0):
 *    a. No colocaron los puntos de poder que tiene el
 *       personaje disponible en cada turno y que le per-
 *       mite el uso de las cartas del mini-deck.
 *    b. El mini-deck no se resetea en cada turno.
 *    c. Las rondas o turnos están mal contabilizados.
 *    d. Al verificar la vida del jugador en la condición
 *       del while, están usando el índice_11, mismo que
 *       se calcula con % 11. El problema es que el arre-
 *       glo que corresponde a la vida de los personajes
 *       tiene un size de 3, por lo que puede llegar a ge-
 *       nerarse inconsistencias. Aquí se aprecia una de
 *       las razones para usar constantes simbólicas.
 *    e. No hay una opción para terminar el turno del ju-
 *       gador.
 *    f. Las cartas utilizadas en cada turno no se inhabi-
 *       litan. 
 * 3. No había necesidad de utilizar estructuras condicio-
 *    nales (if y switch) ni para construir el mini-deck,
 *    ni para seleccionar las cartas al momento de atacar.
 *    Esto lo que causa es repetición de código, una mala
 *    práctica que debe evitarse siempre (-0.3).
 * 4. En este punto, una buena forma de implementar el mi-
 *    ni-deck era almacenando los índices aleatorios en un
 *    arreglo de tamaño 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>





int Batalla(char (*nombre_Enemigos)[100], int* vida_enemigos, char (*nombre_Jugador)[100], int* ataque_Cartas, int* vida_jugador, char (*nombre_cartas)[100]);

int Batalla(char (*nombre_Enemigos)[100], int* vida_enemigos, char (*nombre_Jugador)[100], int* ataque_Cartas, int* vida_jugador, char (*nombre_cartas)[100]) {
    int ataque_enemigo = 20, i=1, j, escoger, carta1, carta2, carta3, turno = 0;
    int indice_11 = rand() % 11;
    int indice_10 = rand() % 10;
    int indice_3 = rand() % 3;
    int vida_actual_enemigo = vida_enemigos[indice_10];
    int vida_actual_jugador = vida_jugador[indice_3];
    printf("Este es tu enemigo %s, hp: %d.\n\n", nombre_Enemigos[indice_11],vida_enemigos[indice_11]);
    for(j=0;j<3;j++){
        int indice_3 = rand() % 5;
        if(j==0){
            carta1 = indice_3;
        }
        if(j==1){
            carta2 = indice_3;
        }
        if(j==2){ 
            carta3 = indice_3;
        }
    }
    while (vida_enemigos[indice_11] > 0 && vida_jugador[indice_11] > 0){
        if(turno == 0){
            printf("Nombre del jugador (%s):\n\n",nombre_Jugador[indice_3]);
            printf("Numero de la ronda: %d.\n\n", i);
            printf("Vida actual del jugador: %d.\n\n", vida_actual_jugador);

            printf("Estas son tus cartas disponibles:\n\n");
            printf("0. %s\n", nombre_cartas[carta1]);
            printf("1. %s\n", nombre_cartas[carta2]);
            printf("2. %s\n", nombre_cartas[carta3]);
            printf("Elige una carta para atacar(0, 1 o 2):\n");
            scanf("%d", &escoger);
    
            switch (escoger)
            {
            case 0:
                printf("Has seleccionado la carta: %s.\n", nombre_cartas[carta1]);
                printf("Ataque con %d de dmg.\n\n", ataque_Cartas[carta1]);
                vida_actual_enemigo -= ataque_Cartas[carta1];
                if(vida_actual_enemigo > 0) printf("Vida actual del enemigo: %d.\n\n",vida_actual_enemigo);
                else{
                    vida_actual_enemigo = 0;
                    printf("Vida actual del enemigo: %d.\n\n",vida_actual_enemigo);
                }
                break;
            case 1:
                printf("Has seleccionado la carta: %s.\n", nombre_cartas[carta2]);
                printf("Ataque con %d de dmg.\n\n", ataque_Cartas[carta2]);
                vida_actual_enemigo -= ataque_Cartas[carta2];
                if(vida_actual_enemigo > 0) printf("Vida actual del enemigo: %d.\n\n",vida_actual_enemigo);
                else{
                    vida_actual_enemigo = 0;
                    printf("Vida actual del enemigo: %d.\n\n",vida_actual_enemigo);
                }
                break;
            case 2:
                printf("Has seleccionado la carta: %s.\n", nombre_cartas[carta3]);
                printf("Ataque con %d de dmg.\n\n", ataque_Cartas[carta3]);
                vida_actual_enemigo -= ataque_Cartas[carta3];
                if(vida_actual_enemigo > 0) printf("Vida actual del enemigo: %d.\n\n",vida_actual_enemigo);
                else{
                    vida_actual_enemigo = 0;
                    printf("Vida actual del enemigo: %d.\n\n",vida_actual_enemigo);
                }
                break;
            default:
                printf("Ingresa un valor valido.");   
                break;
            }

            if (vida_actual_enemigo <= 0)
            {
                printf("Has derrotado al enemigo.\n");
                break; 
            }
            turno = 1;
            i++;
        }
        else{
            printf("Turno del enemigo (%s):\n\n",nombre_Enemigos[indice_11]);
            vida_actual_jugador -= ataque_enemigo;
            printf("Numero de la ronda: %d.\n\n", i);
            printf("%s ataca al jugador. -%d de vida\n\n",nombre_Enemigos[indice_11],ataque_enemigo);

            if(vida_actual_jugador <= 0)
            {
                printf("Te han matado.\n");
                break;
            }
            turno = 0;
            i++;
        }

    }
}

int main(){
    srand(time(NULL));
    char nombresJugadores[3][100] = {"Acosta","Mena","David"};
    char nombre_Enemigos[10][100] = {"Large Slimes","Fungi Beast","Spike Slime","Thieves","Cultist","Gremlins","Nob gremlin","Gremlin Leader","Giant Head","Acid Slime"};
    int vidaEnemigos[10] = {58,28,73,50,56,72,18,90,155,520};
    int vidaJugadores[3] = {88,96,74};
    int ataqueEnemigo[10] = {30,35,13,50,33,15,33,14,23,22};
    int fuerzaJugadores[3] = {72,54,30};
    int inteligencia[3] = {20,32,60};
    char nombreCartas[5][100] = {"Ataque fuerte", "Rayos", "Llamarada", "Congelacion", "Veneno"}; /*Establecer los nombres de las cartas*/
    char descripcionCartas[5][100] = {"Golpea con su ataque mas fuerte, inflije 30 de dmg", "Genera una fuerte descarga, inflije 22 de dmg", "Ataca con ayuda del fuego inflinjiendo 25 de vida", "Golpea al enemigo inmobilizandolo, inflige 21 de dmg", "Genera daño por envenenamiento inflienjiedo, 20 de daño"};
    int ataque_Cartas[5] = {30,22,25,21,20};
    int energia[5] = {30,10,40,30,5}; 
    Batalla(nombre_Enemigos,vidaEnemigos,nombresJugadores,ataque_Cartas,vidaJugadores,nombreCartas);    
}



