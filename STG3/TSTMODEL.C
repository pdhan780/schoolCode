#include "events.h"
#include "model.h"
#include <stdio.h>





int main()

{

struct Spaceship mainPlayer = {300, 300, 1, 16, 16};
struct Asteroid asteroid = {200, 350, 1, 16, 16};

struct Spaceship *shipPtr = &mainPlayer;
struct Asteroid *astPtr = &asteroid;

bool crash = false;
bool crash2 = false;

printf("\nship coords are %d and %d",shipPtr->x, shipPtr->y);
printf("\n");




while(crash2 == false)
{

printf("\nasteroid coords are %d and %d", astPtr->x, astPtr->y);

printf("\n");

move_asteroid(astPtr);

crash2 = bottomCrash(astPtr);

}





while (crash == false){

printf("\nship coords are %d and %d", shipPtr->x,shipPtr->y);

printf("\n");

sideCrash(shipPtr);

crash = collisionDetect(shipPtr, astPtr);
 
}





return 0;

}
