#include "model.h"



void move_spaceship(struct Spaceship *shipPtr)
{

  
       shipPtr->x += shipPtr->deltaX;
     
   
}


void move_asteroid(struct Asteroid *asteroidPtr)
{

  asteroidPtr->y += asteroidPtr->deltaY;


}
