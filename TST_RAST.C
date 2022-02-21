#include <osbind.h>
#include "raster.h"
#define SHIP_HEIGHT 16
#define ASTEROID_HEIGHT 16
#define FONT_HEIGHT 8

typedef UINT16 unsigned_int;


UINT16 spaceship_bitmap[SHIP_HEIGHT]=
{

0x0000,
0x0180,
0x03C0,
0x0FF0,
0x0990,
0x399C,
0x399C,
0xF99F,
0xFFFF,
0x0240,
0x0240,
0x0000,
0x0000,
0x0000,
0x0000,

};


UINT16 asteroid_bitmap[ASTEROID_HEIGHT] =
{
0x0780,
0x0FC0,
0x1FE0,
0x3FF0,
0x7FF8,
0xFFFC,
0xF9FC,
0xF9FC,
0xFFFC,
0x7FF8,
0x3FF0,
0x1FE0,
0x0FC0,
0x0780,
};

UINT8 font_bitmap[FONT_HEIGHT] =
{
0x00,
0x78,
0x84,
0x84,
0xFC,
0x84,
0x84,
0x00
};

int main()
{


	UINT16 *base = (UINT16 *) Physbase();

        
	plot_bitmap_8((char*)base, 300,100,font_bitmap,FONT_HEIGHT);
	
        plot_bitmap_16(base, 300, 200, spaceship_bitmap, SHIP_HEIGHT);   
        
        
  
        plot_bitmap_16(base, -5, -300, spaceship_bitmap, SHIP_HEIGHT);

/* plotting a horizontal line*/
        
/*plotting a vertical line*/
        
/*plotting a diagonal line*/
        plot_line ( (char*)base, 200, 200, 250, 275);

/*plotting a rectangle*/
        plot_rectangle( (char*) base, 100, 100, 60, 80);

	return 0;

}
