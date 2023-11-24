#include "enemy.h"

Enemy* createBestiary() {
    FILE* file = fopen("enemy_data.txt", "r");
    if (file == NULL) {
        printf("Cannot open the file.\n");
        return NULL;
    }

    Enemy* bestiary = (Enemy*) malloc(sizeof(Enemy) * 21);

    for (int i = 0; i < 21; i++) {
        bestiary[i].name = (char*) malloc(sizeof(char) * 50);
        bestiary[i].description = (char*) malloc(sizeof(char) * 100);
        bestiary[i].type = (char*) malloc(sizeof(char) * 50);
        bestiary[i].estate = (char*) malloc(sizeof(char) * 50);
        fscanf(file, "%[^,],%[^,],%[^,],%[^,],%d\n", bestiary[i].name, bestiary[i].description, bestiary[i].type, bestiary[i].estate, &(bestiary[i].health));
    }

    fclose(file);
    return bestiary;
}


void printBestiary(Enemy* bestiary) {
    printf("Bestiario:\n");
    for (int i = 0; i < 21; i++) {
        printf("Enemigo %d:\n", i + 1);
        printf("Nombre: %s\n", bestiary[i].name);
        printf("Descripcion: %s\n", bestiary[i].description);
        printf("Tipo: %s\n", bestiary[i].type);
        printf("Vida: %d\n", bestiary[i].health);
        printf("Estado: %s\n\n", bestiary[i].estate);
    }
}