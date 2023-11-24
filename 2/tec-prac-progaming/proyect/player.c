#include "player.h"


Player* readPlayers() {
    FILE* file = fopen("player_data.txt", "r");
    if (file == NULL) {
        printf("no se puede abrir.\n");
        return NULL;
    }

    Player* characters = malloc(sizeof(Player) * 3);

    for (int i = 0; i < 3; i++) {
        characters[i].character_name = malloc(sizeof(char) * 50);
        fscanf(file, "%[^,],%d,%d,%d,%d,%d\n", characters[i].character_name, &(characters[i].intelligence), &(characters[i].force), &(characters[i].total_character_life), &(characters[i].current_life_character), &(characters[i].character_state));
    }

    fclose(file);
    return characters;
} 

Player selectPlayer(Player* players) {
    printf("personajes disponibles:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, players[i].character_name);
    }

    int opcionPersonaje;
    printf("Elige un personaje: ");
    scanf("%d", &opcionPersonaje);

    return players[opcionPersonaje - 1];
}
