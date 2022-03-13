#ifndef RENDER_H
#define RENDER_H

#include "types.h"
#include "model.h"
#include "raster.h"



void render(const struct Model *model, UINT16 *base, UINT16 *shipBitmap,
            UINT16 *astBitmap,int colLevel,int rowLevel);


void render_spaceship(const struct Spaceship *shipPtr, UINT16 *base,
                      UINT16 *shipBitmap);


void render_asteroid(const struct Asteroid *astPtr, UINT16 *base,
                     UINT16 *astBitmap); 


void render_fleet(const struct Model *model, UINT16 *base, UINT16 *astBitmap,
                 int colLevel, int rowLevel);


#endif
