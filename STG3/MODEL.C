#include "model.h"


/* horizontal move (left or right) for spaceship */
void move_spaceship(struct Spaceship *shipPtr)
{
    shipPtr->oldX = shipPtr->x;
	   
    shipPtr->oldY = shipPtr->y;
 
    shipPtr->x = shipPtr->x + shipPtr->deltaX * shipPtr->direction;
	   
	   
	if (shipPtr->direction == -1 || shipPtr->direction == 1)
     {
          shipPtr->moved = true;
	   
     }
	  
	else
      {
		  
         shipPtr->moved = false;  
		  
       }

       shipPtr->direction = 0;
        
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
