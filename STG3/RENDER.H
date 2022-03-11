#ifndef RENDER_H
#define RENDER_H

#include "types.h"
#include "model.h"
#include "raster.h"



void render(struct Model *model, UINT16 *base, UINT16 *shipBitmap,
            UINT16 *astBitmap, unsigned int colLevel, unsigned int rowLevel);


void render_spaceship(const struct Spaceship *shipPtr, UINT16 *base,
                      UINT16 *shipBitmap);


void render_asteroid(const struct Asteroid *astPtr, UINT16 *base, UINT16 *astBitmap); 




 








#endif
