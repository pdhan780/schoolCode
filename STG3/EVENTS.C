#include "events.h"

/**
* moveSafe: allows user to move spaceship until left or right boundry
* inputs: shipPtr --- pointer to spaceship structure
*
**/



void moveSafe(struct Spaceship *shipPtr){

  int leftBound = 2;

  int rightBound = 608;

  if (shipPtr->x > leftBound && shipPtr->direction == -1 )
  {


    move_effect();
  
    move_spaceship(shipPtr);
        

  }

     

  if (shipPtr->x <= rightBound && shipPtr->direction == 1)
  {

    move_effect();

    move_spaceship(shipPtr);

    

  }


}

/**
*bottomCrash signals when a asteroid has collided with bottom
*inputs - astPtr is a pointer to a asteroid 
*
**/


bool bottomCrash(struct Asteroid *astPtr)
{

  bool crash = false;

  if(astPtr->y >= 399 && astPtr->deltaY >0)

 {

    return crash = true;

 }

  return crash;

}



/**
*collisionDetect is the main collision handler between a spaceship & asteroid
*
* inputs- pointers to asteroid and ship are taken in. The collison detetction
* works by using the width and height of the game objects for hitboxes.
* If one of the objects enters into the others 16x16 hitbox, a collison
* is signaled. 
**/

bool collisionDetect(struct Spaceship *shipPtr, struct Asteroid *astPtr)
{


bool crash = false;
int boxSize = 16;

if (shipPtr->x >= astPtr->x  && shipPtr->x <= astPtr->x + boxSize &&
    shipPtr->y >= astPtr->y  && shipPtr->y <=
    astPtr->y + boxSize)
{


    return crash = true;

}



if(astPtr->x >= shipPtr->x && astPtr->x <= shipPtr->x + boxSize &&
   astPtr->y >= shipPtr->y && astPtr->y <= shipPtr->y + boxSize)
{

  return crash = true;

} 



    return crash;
}



bool collision_detect_fleet(const struct Model *model, int colLevel, 
                            int rowLevel)
{

  bool crash = false;

  int counter = 0;

  if ( rowLevel <=9 && rowLevel >=0 )

  {
    while(counter <=colLevel )

    {
      crash = collisionDetect(&(model->gameShip), 
              &(model->asteroids[rowLevel][counter]));

      if( crash == true )

      {


        explosion_effect();

        return crash;

      }

      counter++;
    }

  }


  return crash;
  
}
