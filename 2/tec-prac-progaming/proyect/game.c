#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "node.h"
#include "player.h"
#include "card.h"
#include "enemy.h"

/* Jose David Ruano 
Andres Acosta
Juan pablo mena*/

// Estructura para guardar el progreso del jugador
int newGame();
int newGame() {
    
    Player* characters = readPlayers();
    
    if (characters == NULL) {
        return 1;  // Si no se pueden leer los personajes, termina el programa
    }

    Player player_Select = selectPlayer(characters);
    printf("Has elegido a %s.\n", player_Select.character_name);

   
    player_Select.deck = createDeck();
    int option;
    do {
        printf("1. Explorar\n");
        printf("2. Deck\n");
        printf("3. Bestiario\n");
        printf("4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &option);
        

        switch (option) {
            case 1:
                printf("Explorando...\n");
                
                break;
            case 2:
                printf("Abriendo deck...\n");
                
                display(player_Select.deck);
                break;
            case 3:
                printf("Abriendo Bestiario...\n");

                Enemy* bestiary = createBestiary();
                printBestiary(bestiary);
                break;
            case 4:
                printf("Regresando al menú principal...\n");
                return 0;  // Si el jugador elige salir, vuelve al menú principal
            default:
                printf("Opción no válida. Por favor, elige una opción entre 1 y 4.\n");
                break;
        }
    } while (option != 4);

    return 1;  // Si se sale del bucle, termina el programa
}


int main (){
    

    int finish = 0;
    do {
        printf("--- BIVENIDO A EL NOMBRE DEL JUEGO --\n");
        printf("1. Juego nuevo\n");
        printf("2. Salir\n");
        printf("3. Continuar\n");

        int selection;
        scanf("%d", &selection);

        switch (selection)
        {
            case 1:
                printf("Iniciando nuevo juego\n");
                finish = newGame();
                
                
                break;
            case 2:
                printf("Saliendo del juego...\n");
                finish = 1;
                break;
            case 3:
                printf("Cargardo tu juego espera...\n");
                // continueGame(&progreso);
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (!finish);

    
    
    return 0;
}
