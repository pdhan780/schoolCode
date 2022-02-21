#include "events.h"
#include "model.h"






void sideCrash(struct Spaceship *shipPtr){

  

  if (shipPtr->x != 0 && shipPtr->deltaX < 0)
  {
    move_spaceship(shipPtr);

  }

   
  if (shipPtr->x != 640 && shipPtr->deltaX >0)
  {
   move_spaceship(shipPtr);

  }


}


bool bottomCrash(struct Asteroid *astPtr)
{

 bool crash = false;

  if(astPtr->y == 400 && astPtr->deltaY >0)
 {

  crash = true;

 }

  return crash;

}


bool collisionDetect( struct Spaceship *shipPtr, struct Asteroid *astPtr)
{

bool crash = false;


if ( (shipPtr->x >= astPtr->x) && (shipPtr->x + shipPtr->width <= astPtr->x +
     astPtr->width) && (shipPtr->y >= astPtr->y) && (shipPtr->y +
     shipPtr->height <= astPtr->y + astPtr->height))
   {

     crash = true;

   }


if (shipPtr->x >= astPtr->x  && shipPtr->x <= astPtr->x + astPtr->width &&
    shipPtr->y >= astPtr->y  && shipPtr->y <=
    astPtr->y + astPtr->height)
{


     crash = true;

}


if(astPtr->x >= shipPtr->x && astPtr->x <= shipPtr->x + shipPtr->width &&
   astPtr->y >= shipPtr->y && astPtr->y <= shipPtr->y + shipPtr->height)
{

   crash = true;

} 


    return crash;

}
