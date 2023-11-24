#ifndef __PLAYER_H
#define __PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

typedef struct Player
{
    char *character_name; //Nombre del personaje
    int intelligence; //inteligencia
    int force; //fuerza
    int total_character_life; //vida_total_personaje
    int current_life_character; //vida_actual_personaje
    int character_state; /*1 si esta vivo , 0 si esta muerto  estado_personaje*/
    int character_power_points; //puntos_poder_personaje
    Node* deck; 
}Player;

Player* readPlayers();
Player selectPlayer(Player* personajes);

#endif