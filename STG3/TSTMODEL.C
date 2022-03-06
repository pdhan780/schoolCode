#include <stdio.h>
#include <osbind.h>

#include "events.h"
#include "model.h"
#include "render.h"
#include "raster.h"
#include "types.h"


#define HEIGHT 16
#define WIDTH 640
#define SCREEN_HEIGHT 400

UINT16 spaceship_bitmap[HEIGHT]=
{

0x0000,
0x0180,
0x03C0,
0x0FF0,
0x0990,
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

UINT16 asteroid_bitmap[HEIGHT] =
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

int main()

{

UINT16 *base = (UINT16 *) Physbase();

bool crash = false;

struct Spaceship mainPlayer = {225, 250, 1, 16, 16};
struct Asteroid asteroid = {300, 250, 0, 16, 16};

struct Spaceship *shipPtr = &mainPlayer;
struct Asteroid *astPtr = &asteroid;





printf("\n");
printf("\nship coords are %d and %d",shipPtr->x, shipPtr->y);
printf("\n");


/*test render begins here */
render_spaceship(shipPtr, base, spaceship_bitmap);
render_asteroid(astPtr, base, asteroid_bitmap);






while ( crash == false )

{

 crash = collisionDetect(shipPtr, astPtr); 

 moveSafe(shipPtr);

 render_spaceship (shipPtr, base, spaceship_bitmap);

 render_asteroid (astPtr, base, asteroid_bitmap);
 
 clear_screen (base, WIDTH, SCREEN_HEIGHT);
 
}




return 0;



}
