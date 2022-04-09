/******************

-Raster Module
-Contains plotting routines for bitmaps as well as clear screen routines
-Authors: Pelvain Dhanda, Nimrat Brar
******************************/

#ifndef RASTER_H
#define RASTER_H

#include "types.h"

#define SPLASH_SIZE 8000

/* This function takes in the screen buffer, the desired x and y coordinates
for the bitmap and a UINT16 bitmap to plot. This function plots a UINT16
bitmap onto the screen buffer*/
void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap,
                    unsigned int height);

/* This function takes in the screen buffer, the desired x and y coordinates
for the bitmap and a UINT8 bitmap to plot. This function plots a UINT8
bitmap onto the screen buffer*/
void plot_bitmap_8( char *base, int x, int y, const UINT8 *bitmap,
                    unsigned int heght);

/* this function takes in the screen buffer and the UINT32 bitmap
for the desired splash screen. This function plots UINT32 bitmap onto
the screen buffer*/
void plot_screen(UINT32 *base, const UINT32 *bitmap);

/* This function takes in the screen buffer, x and y coordinates.
It then plots a pixel at the position specified by the x and y coordinates.
*/
void plot_pixel (char *base, int x, int y);

/* This function takes in the screen buffer, and following x,y coordinates
to plot onto the screen buffer */
void plot_line (char *base, int x1, int y1, int x2, int y2);

/* This function takes in the screen buffer, x and y coordinates, aswell as
the desired length and width of the rectangle. It then uses the x, y, width, and 
length parameters and plots it onto the screen buffer. */
void plot_rectangle (char *base, int x, int y, int width, int length);

/* This function takes in the screen buffer, 
the specified x and y coordinates and the width of line. 
It uses these parameters and clears that section of the screen buffer */
void clear_line (UINT16 *base, int x, int y, int width);

/* This function takes in the screen buffer and the width and height 
that is desired to be cleared. The position at where the clearing begins is
the top left of the screen buffer so coordinates x and y equal to 0. */
void clear_screen (UINT16 *base, int width, int height);

#endif
