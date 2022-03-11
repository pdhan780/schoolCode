#include "render.h"






void render(struct Model *model, UINT16 *base, UINT16 *ship, UINT16 *asteroid,
            int colLevel, int rowLevel) 

{

 render_spaceship(&model->gameShip,base,ship); 

 render_fleet (model,base,asteroid, colLevel, rowLevel);

 
}


void render_spaceship(const struct Spaceship *shipPtr, UINT16 *base, UINT16 *ship){

 plot_bitmap_16 (base, shipPtr->x, shipPtr->y,ship, shipPtr->height); 

}




void render_asteroid(const struct Asteroid *astPtr, UINT16 *base,
                     UINT16 *asteroid)
{

 plot_bitmap_16 (base, astPtr->x, astPtr->y, asteroid, astPtr->height);

}





void render_fleet(struct Model *model, UINT16 *base, UINT16 *asteroid,
                  int colLevel, int rowLevel)
                   
{



/*row levels 0-9*/
									````	/*assume rowLevel to be a constant number*/
/*process for the row given, and plot the amount of asteroids*/



if (rowLevel < 0 && rowLevel <=9) {   


    int x;

    for (x = 0; x < colLevel; x++)
  {


   render_asteroid(model->asteroids[rowLevel][x], base, asteroid);


  }


 }




}



