#ifndef __CARD_H
#define __CARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "player.h"

typedef struct Card
{
    char* name; //Nombre
    char* description; //descripcion
    char* type; //tipo
    int value_use; //valor uso
    int value_damage; //valor daño
}Card;

/* Card* chooseCard(Player* player); */

#endif
