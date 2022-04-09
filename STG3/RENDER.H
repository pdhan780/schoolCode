**
-Render Module
-Supports routine for rendering game objects
-Authors: Pelvain Dhanda, Nimrat Brar
**/

#ifndef RENDER_H
#define RENDER_H

#include "types.h"
#include "model.h"
#include "raster.h"
#include "splash.h"

/* This is the master render */
void render(const struct Model *model, UINT16 *base, UINT16 *shipBitmap,
            UINT16 *astBitmap,int colLevel,int rowLevel);

/* This function takes in a spaceship pointer, the screen buffer and, the spaceship
bitmap and renders a spaceship */
void render_spaceship(const struct Spaceship *shipPtr, UINT16 *base,
                      UINT16 *shipBitmap);

/* This function takes in an asteroid pointer, screen buffer and asteroid bitmap
and renders an asteroid. */
void render_asteroid(const struct Asteroid *astPtr, UINT16 *base,
                     UINT16 *astBitmap); 

/* This function takes in the model, the screen buffer, asteroid bitmap, and 
renders all the asteroids in the array that is defined in dodger.c */
void render_fleet(const struct Model *model, UINT16 *base, UINT16 *astBitmap,
                 int colLevel, int rowLevel);
				 
/* This function when called, takes in the screen buffer and plots the splash_screen 
bitmap onto that screen buffer. */
void render_splashscreen(UINT32 *base);


#endif
