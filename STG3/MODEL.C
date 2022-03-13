#include "model.h"


/* horizontal move (left or right) for spaceship */
void move_spaceship(struct Spaceship *shipPtr)
{

  
       shipPtr->x += shipPtr->deltaX;
     
   
}

/* vertical move (down only) for spaceship */

void move_asteroid(struct Asteroid *asteroidPtr)
{

  asteroidPtr->y += asteroidPtr->deltaY;


}



void move_fleet(struct Model *modelPtr, int colLevel, int rowLevel)
{

  int x;

 if (rowLevel >=0 && rowLevel <= 9)
{



  for (x = 0; x <= colLevel; x++)

  {
   

    move_asteroid( &(modelPtr->asteroids[rowLevel][x]));


   }


 }



}

