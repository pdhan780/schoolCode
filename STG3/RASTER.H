/******************

-Raster Module
-Contains plotting routines for bitmaps as well as clear screen routines
-Authors: Pelvain Dhanda, Nimrit Brar
******************************/

#ifndef RASTER_H
#define RASTER_H

#include "types.h"

#define SPLASH_SIZE 8000


void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap,
                    unsigned int height);

void plot_bitmap_8( char *base, int x, int y, const UINT8 *bitmap,
                    unsigned int heght);


void plot_screen(UINT32 *base, const UINT32 *bitmap);

void plot_pixel (char *base, int x, int y);

void plot_line (char *base, int x1, int y1, int x2, int y2);

void plot_rectangle (char *base, int x, int y, int width, int length);

void clear_line (UINT16 *base, int x, int y, int width);

void clear_screen (UINT16 *base, int width, int height);

#endif
