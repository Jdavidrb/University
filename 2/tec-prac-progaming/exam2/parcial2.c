 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Jose David Ruano 
Andres Acosta
Juan pablo mena*/

typedef struct Personaje
{
    char *nombre_personaje;
    int inteligencia;
    int fuerza;
    int vida_total_personaje;
    int vida_actual_personaje;
    int estado_personaje; /*1 si esta vivo , 0 si esta muerto*/
    int puntos_poder_personaje;
}Personaje;

typedef struct Carta
{
    char* nombre_carta ;
    char* descripcion_carta;
    int valor_ataque;
    int valor_uso;
}Carta;


typedef struct Enemigo {
    char* nombre_enemigo;
    char* descripcion_enemigo;
    int vida_total_enemigo;
    int vida_actual_enemigo;
    int accion; /*si es 1 ataca , si es 2 se cura*/
    int estado_enemigo; /*1 si esta vivo , 0 si esta muerto*/
    int ataque_enemigo;
    int curacion_enemigo;
} Enemigo;


int main() {
    srand(time(NULL));
    
    /*DATOS */

    /* personajes */

    char* nombres_personajes[] = {"Caballero"};
    int inteligencias_personajes[] = {20};
    int vidas_totales_personajes[] = {40};
    int vidas_actuales_personajes[] = {40};
    int estados_personajes [] = {1};
    int fuerzas_personajes[] = {10};

    Personaje personajes[1]; /* por ahora solo tenemos un personaje disponible*/
    for(int i = 0; i < 1; i++) {
        personajes[i].nombre_personaje = malloc(strlen(nombres_personajes[i] + 1 ) * sizeof(char));
        strcpy(personajes[i].nombre_personaje , nombres_personajes[i]);

        personajes[i].inteligencia = inteligencias_personajes[i];
        personajes[i].vida_total_personaje = vidas_totales_personajes[i];
        personajes[i].vida_actual_personaje = vidas_actuales_personajes[i];
        personajes[i].fuerza = fuerzas_personajes[i];
        personajes[i].estado_personaje = estados_personajes[i];
        personajes[i].puntos_poder_personaje = 3;

    }


    /* cartas */

    char* nombres_cartas[] = { 
        "Ataque fuerte", 
        "Rayos", 
        "Llamarada", 
        "Congelacion", 
        "Veneno",
        "Terremoto",
        "Tornado",
        "Inundacion",
        "Tormenta de arena",
        "Erupcion volcanica",
        "Ataque fuerte", 
        "Rayos", 
        "Llamarada", 
        "Congelacion", 
        "Veneno",
        "Terremoto",
        "Tornado",
        "Inundacion",
        "Tormenta de arena",
        "Erupcion volcanica"
    };

    char* descripciones_cartas[] = { 
        "Esta carta permite al jugador infligir 30 puntos de dano. Consume 2 puntos de energia.",
        "Esta carta permite al jugador lanzar un rayo que causa 22 puntos de dano. Consume 1 punto de energia.",
        "Esta carta permite al jugador desatar una llamarada que causa 25 puntos de dano. Consume 1 punto de energia.",
        "Esta carta permite al jugador congelar al oponente, causando 21 puntos de dano. Consume 1 punto de energia.",
        "Esta carta permite al jugador envenenar al oponente, causando 20 puntos de dano. Consume 1 punto de energia.",
        "Esta carta permite al jugador desatar un terremoto que causa 19 puntos de dano. Consume 1 punto de energia.",
        "Esta carta permite al jugador convocar un tornado que causa 21 puntos de dano. Consume 2 puntos de energia.",
        "Esta carta permite al jugador causar una inundacion que causa 25 puntos de dano. Consume 3 puntos de energia.",
        "Esta carta permite al jugador desatar una tormenta de arena que causa 40 puntos de dano. Consume 2 puntos de energia.",
        "Esta carta permite al jugador provocar una erupcion volcanica que causa 36 puntos de dano. Consume 2 puntos de energia.",
        "Esta carta permite al jugador desatar una explosion que causa 35 puntos de dano. Consume 3 puntos de energia.",
        "Esta carta permite al jugador convocar una lluvia acida que causa 23 puntos de dano. Consume 2 puntos de energia.",
        "Esta carta permite al jugador desatar un vendaval que causa 28 puntos de dano. Consume 2 puntos de energia.",
        "Esta carta permite al jugador provocar un deslizamiento de tierra que causa 26 puntos de dano. Consume 2 puntos de energia.",
        "Esta carta permite al jugador lanzar un rayo solar que causa 30 puntos de dano. Consume 2 puntos de energia.",
        "Esta carta permite al jugador desatar una avalancha que causa 33 puntos de dano. Consume 3 puntos de energia",
        "Esta carta permite al jugador convocar un tsunami que causa 40 puntos de dano. Consume 3 puntos de energia.",
        "Esta carta permite al jugador causar un incendio forestal que causa 35 puntos de dano. Consume 3 puntos de energia.",
        " Esta carta permite al jugador desatar una tormenta de granizo que causa 25 puntos de dano. Consume 2 puntos de energia.",
        "Esta carta permite al jugador lanzar un meteoro que causa 45 puntos de dano. Consume 3 puntos de energia."
    };


    int valores_ataque [] = {30,22,25,21,20,19,21,25,40,36,30,22,25,21,20,19,21,25,40,36};
    int valores_uso[] = {2,1,1,1,1,1,1,2,3,2,2,1,1,1,1,1,1,2,3,2};

    /* Arreglo para almacenar todas las cartas del juego */
    Carta cartas[20];

    /* Llenamos los datos de las cartas en el arreglo*/
    for(int i = 0; i < 20; i++) {
        cartas[i].nombre_carta = malloc((strlen(nombres_cartas[i]) + 1) * sizeof(char));
        strcpy(cartas[i].nombre_carta, nombres_cartas[i]);

        cartas[i].descripcion_carta = malloc((strlen(descripciones_cartas[i]) + 1) * sizeof(char));
        strcpy(cartas[i].descripcion_carta, descripciones_cartas[i]);

        cartas[i].valor_ataque = valores_ataque[i];

        cartas[i].valor_uso = valores_uso[i];
    }
    

    

    /* enemigos */            
    
    char* nombres_enemigos[] = {"Slimes", "Fungi Beast", "Spike Slime", "Thieves", "Cultist", "Acid Slime", "Gremlins", "Nob gremlin", "Gremlin Leader", "Giant Head"};
    char* descripciones_enemigos[] = {

        "Cuando su HP este en el 50 o menos, se dividira en 2 Slimes mas pequenos con su HP actual.", 
        "Al morir, aplica X Vulnerable al jugador.", 
        "Cuando su HP este en el 50 o menos, se dividira en 2 Slimes mas pequenos con su HP actual.", 
        "X Gold es robado con cada ataque. El oro total robado se devuelve si el enemigo muere.", 
        "Al final de su turno, gana X Fuerza", 
        "Cuando su HP este en el 50 o menos, se dividira en 2 Slimes mas pequenos con su HP actual.", 
        "Aumenta la fuerza en X al recibir dano de ataque", 
        "Cada vez que juegas una Habilidad , gana X Fuerza", 
        "Se cura 20 puntos cada tres turnos", 
        "50 de probabilidad de impactar criticos"
    };

    int vidas_totales_enemigos[] = {52, 28, 73, 50, 56, 72, 18, 90, 55, 60};
    int vidas_actuales_enemigos[] = {52, 28, 73, 50, 56, 72, 18, 90, 55, 60};
    int estados_enemigos[] = {1,1,1,1,1,1,1,1,1,1};

    /*Arreglo de enemigos*/
    Enemigo enemigos[10];


     /*llenamos el arreglo con los datos de los enemigos*/
                
    for(int i = 0; i < 10; i++) {
        enemigos[i].nombre_enemigo = malloc((strlen(nombres_enemigos[i]) + 1) * sizeof(char));
        strcpy(enemigos[i].nombre_enemigo, nombres_enemigos[i]);

        enemigos[i].descripcion_enemigo = malloc((strlen(descripciones_enemigos[i]) + 1) * sizeof(char));
        strcpy(enemigos[i].descripcion_enemigo, descripciones_enemigos[i]);

        enemigos[i].vida_total_enemigo = vidas_totales_enemigos[i];
        enemigos[i].vida_actual_enemigo = vidas_actuales_enemigos[i];

        enemigos[i].estado_enemigo = estados_enemigos[i];
        
        enemigos[i].ataque_enemigo = 20;
        enemigos[i].curacion_enemigo = 20;
    }

    
    

    

    /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    int num_cartas;
    num_cartas = 6; /* cartas iniciales */

    /* Creamos el deck dinamico */
    Carta *deck = malloc(num_cartas * sizeof(Carta)); 


    for(int i = 0; i < num_cartas; i++) {
        int carta_aleatoria = rand() % 20; /* Genera un número aleatorio entre 0 y 19 */
        deck[i].nombre_carta = nombres_cartas[carta_aleatoria];
        deck[i].descripcion_carta = descripciones_cartas[carta_aleatoria];
        deck[i].valor_ataque = valores_ataque[carta_aleatoria];
        deck[i].valor_uso = valores_uso[carta_aleatoria];
    }

    /* MENU PRINCIPAL */

    int seleccionar = 0;
    while (seleccionar != 4) {
        printf("Seleccionar opcion:\n");
        printf("1. Explorar\n2. Deck\n3. Bestiario\n4. Salir\n");
        scanf("%d", &seleccionar);

        switch (seleccionar) {
            case 1:
                printf("Explorando...\n\n");

                /* LOGICA DE COMBATE*/

                /* crear mini deck */
                int cartas_seleccionadas[5] = {0,0,0,0,0};
                Carta *mini_deck = malloc(5 * sizeof(Carta));
                
                for (int i = 0; i < 5; i++) {
                    int carta_aleatoria = rand()% 6;
                    mini_deck[i].nombre_carta = deck[carta_aleatoria].nombre_carta;
                    mini_deck[i].valor_ataque = deck[carta_aleatoria].valor_ataque;
                    mini_deck[i].valor_uso = deck[carta_aleatoria].valor_uso;
                }
                
                /* Escojer el enemigo con el que vamos a pelear*/

                int indice_personaje = 0;
                int indice_enemigo_inicial = rand() % 10;
                int indice_enemigo = 0;

                /* Verificar que el enemigo no se haya derrotado antes */
                
                while(indice_enemigo == 0){
                    if(enemigos[indice_enemigo_inicial].estado_enemigo == 1){
                        indice_enemigo = indice_enemigo_inicial;
                    }
                    else{
                        indice_enemigo_inicial = rand() % 10;
                    }
                }
            
                int indice_accion_enemigo = rand()% 1; /* solo dos acciones posibles para el enemigo, si 0 ataca, si 1 se cura */

                personajes[indice_personaje].vida_actual_personaje = personajes[indice_personaje].vida_total_personaje; /* la vida del personaje se inicializa en su vida maxima*/


                /* IMPRESION DE LA INTERFAZ */

                printf(" Te has encontrado con un %s de vida %dph\n\n", enemigos[indice_enemigo].nombre_enemigo,enemigos[indice_enemigo].vida_total_enemigo); 
                printf(" Tu personaje es %s tienes una vida total de %dph\n\n", personajes[indice_personaje].nombre_personaje , personajes[indice_personaje].vida_total_personaje);

                int estado_enemigo = enemigos[indice_enemigo].estado_enemigo;
                int estado_personaje = personajes[indice_personaje].estado_personaje;
                int turno = 0; /*0 : turno del personaje , 1: turno del del enemigo*/

                while(estado_enemigo == 1 && estado_personaje == 1){ /* con que uno murera el bucle acaba */
                    if(turno == 0){
                        personajes[indice_personaje].puntos_poder_personaje = 3; /* los puntos inicializan siempre en 3*/
                        /* interfaz usuario */
                        printf( "---Info enemigo---\n");
                        printf(" Enemigo: %s | Vida: %d \n", enemigos[indice_enemigo].nombre_enemigo, enemigos[indice_enemigo].vida_actual_enemigo);
                            
                            
                        if(indice_accion_enemigo == 0){
                            printf(" (El enemigo se prepara para atacar - %d damage)\n\n" ,enemigos[indice_enemigo].ataque_enemigo );

                        }
                        else{
                            printf(" (El enemigo se prepara para curarse %d de vida)\n\n", enemigos[indice_enemigo].curacion_enemigo);
                        }
                            
                        printf(" ---Info personaje---\n");
                        printf(" Personaje: %s | Vida: %d", personajes[indice_personaje].nombre_personaje, personajes[indice_personaje].vida_actual_personaje);
                        printf(" Puntos de poder: %d\n\n", personajes[indice_personaje].puntos_poder_personaje);
                        printf(" Mini deck: \n");
                        
                        
                        for(int i = 0; i < 5; i++ ){
                            if (mini_deck[i].nombre_carta != "Null")
                                printf(" %d) %s , Damage: %d , Costo de uso: %d\n", (i+1), mini_deck[i].nombre_carta, mini_deck[i].valor_ataque, mini_deck[i].valor_uso);
                        
                        }
                        printf("\n");
                        printf(" 6) Terminar turno\n\n");

                        /* eliga la carta o la opcion */
                        int flag = 1;
                        while(flag != 0){
                            int seleccion;
                            printf(" Elige la opcion: ");
                            scanf(" %d" ,&seleccion);
                            printf("\n");
                            if(seleccion < 6 && seleccion > 0){
                                if(personajes[indice_personaje].puntos_poder_personaje > 0 && mini_deck[seleccion -1].valor_uso <= personajes[indice_personaje].puntos_poder_personaje  && cartas_seleccionadas[seleccion-1] == 0 ){ /*veficar que los puntos del personaje no sean ningunos o 0*/
                                        enemigos[indice_enemigo].vida_actual_enemigo  -= mini_deck[seleccion-1].valor_ataque; /* ataque al eneimgo */
                                        personajes[indice_personaje].puntos_poder_personaje -= mini_deck[seleccion-1].valor_uso;/* restar puntos usados */

                                        
                                        cartas_seleccionadas[seleccion-1] = 1;


                                        if (personajes[indice_personaje].vida_actual_personaje < 0){
                                            
                                            estado_personaje = 0;
                                            printf("\n");
                                            printf(" ---JUEGO TERMINADO---\n\n");
                                            printf(" EL ENEMIGO TE HA DERROTADO \n\n");
                                            turno = 3;
                                            flag = 0;

                                        }
                                        else if(enemigos[indice_enemigo].vida_actual_enemigo < 0) {
                                            enemigos[indice_enemigo].estado_enemigo = 0;
                                            estado_enemigo = 0;
                                            printf("\n");
                                            printf(" ---JUEGO TERMINADO---\n\n");
                                            printf(" HAS DERROTADO AL ENEMIGO \n\n");
                                            turno = 3;
                                            flag = 0;

                                        }
                                        else{
                                            printf(" Has atacado al enemigo con %s %d damage\n",mini_deck[seleccion-1].nombre_carta, mini_deck[seleccion-1].valor_ataque);
                                            mini_deck[seleccion-1].nombre_carta = "Null";
                                            printf(" La vida actual del enemigo es %d\n", enemigos[indice_enemigo].vida_actual_enemigo);
                                            printf(" Te quedan %d puntos de poder\n\n", personajes[indice_personaje].puntos_poder_personaje);
                                            
                                        }
                                }
                                
                                else if(cartas_seleccionadas[seleccion-1] == 1){
                                    printf(" la carta que seleccionaste ya fue usada, por favor escoje otra\n");
                                }
                                else if(mini_deck[seleccion -1].valor_uso > personajes[indice_personaje].puntos_poder_personaje){
                                    printf(" No tienes los puntos suficientes, si es necesario seleciona la opcion 'Teminar turno'\n");
                                }
                            }

                            else if (seleccion == 6){
                                turno = 1;
                                flag = 0;
                                
                            }
                            else{
                                printf("\n");
                                printf(" Ingrese una opcion valida\n");
                            }
                        }
                    }
                    
                    else if(turno == 1){
                        if(indice_accion_enemigo == 0){
                            personajes[indice_personaje].vida_actual_personaje -= enemigos[indice_enemigo].ataque_enemigo;
                            printf(" El enemigo ataco haciendo %d dano \n\n" ,enemigos[indice_enemigo].ataque_enemigo );

                            if (personajes[indice_personaje].vida_actual_personaje <= 0){
                                estado_personaje = 0;
                                printf("\n");
                                printf(" ---JUEGO TERMINADO---\n");
                                printf(" EL ENEMIGO TE HA DERROTADO \n\n");
                            }
                            else if(enemigos[indice_enemigo].vida_actual_enemigo <= 0) {
                                enemigos[indice_enemigo].estado_enemigo = 0;
                                estado_enemigo = 0;
                                printf("\n");
                                printf(" ---JUEGO TERMINADO---\n");
                                printf(" HAS DERROTADO AL ENEMIGO \n\n");

                            }
                            else{
                                turno = 0;
                            }

                        }

                        else{
                            enemigos[indice_enemigo].vida_actual_enemigo += enemigos[indice_enemigo].curacion_enemigo; 
                            printf(" El enemigo se curo %d de vida\n\n", enemigos[indice_enemigo].curacion_enemigo);
                            turno = 0;
                        }
                    }

                }
                
                break;
            case 2:
                printf(" Abriendo Deck...\n");
                /* Imprimimos el deck del jugador */
                for(int i = 0; i < num_cartas; i++) {
                    printf("Nombre: %s\n", deck[i].nombre_carta);
                    printf("Descripcion: %s\n", deck[i].descripcion_carta);
                    printf("Dano: %d\n", deck[i].valor_ataque);
                    printf("Valor de uso: %d\n\n", deck[i].valor_uso);
                }
                /* Liberar la memoria */
                free(deck);

                break;
            case 3:
                printf("Abriendo Bestiario...\n");

                /*Imprimimos los datos*/
                for(int i = 0; i < 10; i++) {
                    printf("Nombre: %s\n", enemigos[i].nombre_enemigo);
                    printf("Descripcion: %s\n", enemigos[i].descripcion_enemigo);
                    printf("Vida: %d\n", enemigos[i].vida_total_enemigo);
                    printf("Estado: %d\n\n", enemigos[i].estado_enemigo);
                }

                break;


            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }
    return 0;
}