#include "render.h"


void render(struct Model *model, UINT16 *base, UINT16 *ship, UINT16 *asteroid) {

 render_spaceship( &model->gameShip,base,ship); 

 
}


void render_spaceship(const struct Spaceship *shipPtr, UINT16 *base, UINT16 *ship){

 plot_bitmap_16 (base, shipPtr->x, shipPtr->y,ship, shipPtr->height); 

}




void render_asteroid(const struct Asteroid *astPtr, UINT16 *base, UINT16 *asteroid)
{

 plot_bitmap_16 (base, astPtr->x, astPtr->y, asteroid, astPtr->height);

}


