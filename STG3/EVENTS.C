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
bool collision_detect_fleet(struct SpaceShip *shipPtr, struct Asteroid * astPtr, const struct Model *model, int colLevel, int rowLevel )
{
  bool crash = false;
  int counter =0;
  if (rowLevel <=9 && rowLevel >=0)
  {
    while(counter <=colLevel)
    {
      crash = collisionDetect(shipPtr, &(model->asteroids[rowLevel][counter]));
      if( crash = true)
      {
        break;
      }
      counter++
    }
  }
  return crash;
  
}
