#ifndef __ENEMY_H
#define __ENEMY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Enemy {
    char* name;
    char* description;
    char* type;
    int health;
    char* estate; /*vivo , muerto*/
    //int damage;
    //int healing;
} Enemy;

Enemy* createBestiary();
void printBestiary(Enemy* bestiary);
           
    
    

#endif