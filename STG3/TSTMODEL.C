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

/* This bitmap is used to clear bitmaps who 
were plotted that are UINT16 */
UINT16 empty[HEIGHT] =
{
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
}; 


int main()

{

UINT16 *base = (UINT16 *) Physbase();
/**
bool crash = false;
bool crash2 = false;
**/

struct Spaceship mainPlayer = {225, 250, 1, 16, 16};
struct Asteroid asteroid = {100, 100, 1, 16, 16};

struct Model gameModel = 
{

    {300, 300, 1 , 16, 16}, /*single spaceship instance */

{
  {
    {1, 0, 1, 16, 16 },   /*beginning of wave 1*/

    {50, 0 , 1 , 16, 16}


  },


  {
    {1, 0, 1, 16, 16}, /*beginning of wave 2*/

    {50, 0, 1, 16, 16},

    {70, 0, 1, 16, 16},

    {80, 0 , 1 , 16, 16}

  },

{

    {1, 0, 1, 16, 16}, /*beginning of wave 3*/

    {50, 0, 1, 16, 16},

    {70, 0, 1, 16, 16},

    {250, 0 , 1 , 16, 16},
    
    {400, 0, 1 , 16, 16},

    {450, 0, 1 , 16, 16}     
     
},


{
    {1, 0, 1, 16, 16}, /*beginning of wave 4*/

    {50, 0, 1, 16, 16},

    {100, 0, 1, 16, 16},

    {250, 0 , 1 , 16, 16},
    
    {400, 0, 1 , 16, 16},
   
    {450, 0, 1 , 16, 16},     
     
    {500, 0, 1, 16, 16},

    {600, 0, 1, 16, 16}


},



{                           

  

   {1, 0, 1, 16, 16},        /*beginning of wave 5*/

   {50, 0, 1, 16, 16},

   {100, 0, 1, 16, 16},

   {250, 0 , 1 , 16, 16},
    
   {400, 0, 1 , 16, 16},
   
   {450, 0, 1 , 16, 16},     
     
   {540, 0, 1, 16, 16},

   {595, 0, 1, 16, 16},

   {600, 0, 1, 16, 16},

   {630, 0, 1, 16, 16}

},



{



   {1, 0, 1, 16, 16},        /*beginning of wave 6*/

   {50, 0, 1, 16, 16},

   {100, 0, 1, 16, 16},

   {150, 0, 1, 16, 16},

   {200, 0, 1, 16, 16},

   {250, 0 , 1 , 16, 16},
    
   {300, 0, 1 , 16, 16},
   
   {450, 0, 1 , 16, 16},     
     
   {540, 0, 1, 16, 16},

   {595, 0, 1, 16, 16},

   {615, 0, 1, 16, 16},

   {630, 0, 1, 16, 16}

   
},






 {

   {1, 0, 1, 16, 16},
                        /*beginning of wave 7*/
   {30, 0, 1, 16, 16},
      
   {50, 0, 1, 16, 16},

   {100, 0, 1, 16, 16},

   {150, 0, 1, 16, 16},

   {200, 0, 1, 16, 16},

   {250, 0 , 1 , 16, 16},
    
   {300, 0, 1 , 16, 16},
  
   {350, 0, 1, 16, 16},
 
   {450, 0, 1 , 16, 16},     
     
   {540, 0, 1, 16, 16},

   {595, 0, 1, 16, 16},

   {615, 0, 1, 16, 16},

   {640, 0, 1, 16, 16}


 },


  {


   {0, 0, 1, 16, 16},
                        /*beginning of wave 8*/
   {32, 0, 1, 16, 16},
      
   {64, 0, 1, 16, 16},

   {96, 0, 1, 16, 16},

   {128, 0, 1, 16, 16},

   {160, 0, 1, 16, 16},

   {192, 0 , 1 , 16, 16},
    
   {224, 0, 1 , 16, 16},
  
   {256, 0, 1, 16, 16},
 
   {288, 0, 1 , 16, 16},     
     
   {320, 0, 1, 16, 16},

   {352, 0, 1, 16, 16},

   {384, 0, 1, 16, 16},

   {416, 0, 1, 16, 16},

   {448, 0 , 1, 16, 16},

   {480, 0, 1, 16, 16}


  },


{




   {0, 0, 1, 16, 16},
                        /*beginning of wave 9*/
   {32, 0, 1, 16, 16},
      
   {64, 0, 1, 16, 16},

   {96, 0, 1, 16, 16},

   {128, 0, 1, 16, 16},

   {160, 0, 1, 16, 16},

   {192, 0 , 1 , 16, 16},
    
   {224, 0, 1 , 16, 16},
  
   {256, 0, 1, 16, 16},
 
   {288, 0, 1 , 16, 16},     
     
   {320, 0, 1, 16, 16},

   {352, 0, 1, 16, 16},

   {384, 0, 1, 16, 16},

   {416, 0, 1, 16, 16},

   {448, 0 , 1, 16, 16},

   {480, 0, 1, 16, 16},

   {512, 0, 1, 16, 16},
    
   {544, 0, 1, 16, 16}

 
  },


{

  
   {0, 0, 1, 16, 16},
                        /*beginning of wave 10*/
   {32, 0, 1, 16, 16},
      
   {64, 0, 1, 16, 16},

   {96, 0, 1, 16, 16},

   {128, 0, 1, 16, 16},

   {160, 0, 1, 16, 16},

   {192, 0 , 1 , 16, 16},
    
   {224, 0, 1 , 16, 16},
  
   {256, 0, 1, 16, 16},
 
   {288, 0, 1 , 16, 16},     
     
   {320, 0, 1, 16, 16},

   {352, 0, 1, 16, 16},

   {384, 0, 1, 16, 16},

   {416, 0, 1, 16, 16},

   {448, 0 , 1, 16, 16},

   {480, 0, 1, 16, 16},

   {512, 0, 1, 16, 16},
    
   {544, 0, 1, 16, 16},

   {576, 0, 1, 16, 16},

   {608, 0 , 1,16, 16}


 }

} /*end of 2D wave array */

}; /*end of model struct*/




struct Spaceship *shipPtr = &mainPlayer;
struct Asteroid *astPtr = &asteroid;
struct Model *modelPtr = &gameModel;

unsigned int oldX;
unsigned int oldY;
int colLevel = 19;
int rowLevel = 9;


printf("\n");
printf("\nship coords are %d and %d",shipPtr->x, shipPtr->y);
printf("\n");


/*test render begins here */
/*render_spaceship(shipPtr, base, spaceship_bitmap);*/
/*render_asteroid(astPtr, base, asteroid_bitmap);*/
render(modelPtr, base, spaceship_bitmap, asteroid_bitmap, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);

move_fleet(modelPtr, colLevel, rowLevel);


render(modelPtr, base, spaceship_bitmap, asteroid_bitmap,colLevel, rowLevel);

printf("\n");
printf("\nasteroid coords are %d and %d", modelPtr->asteroids[9][0].x,
       modelPtr->asteroids[9][0].y);

printf("\n");


/*spaceship render here*/

/**
while ( crash == false )
{
 crash = collisionDetect(shipPtr, astPtr);  
 oldX = shipPtr->x;
 oldY = shipPtr->y;
 moveSafe(shipPtr);
 render_spaceship (shipPtr, base, spaceship_bitmap);
 render_asteroid (astPtr, base, asteroid_bitmap);
 
 plot_bitmap_16 (base, oldX, oldY, empty, HEIGHT);
 
}
**/



/*asteroid render here */

/**
while ( crash2 == false)
{

  crash2 = bottomCrash(astPtr);

  oldX = astPtr->x;

  oldY = astPtr->y;

  move_asteroid(astPtr);

  render_asteroid(astPtr,base,asteroid_bitmap);
 
  plot_bitmap_16(base, oldX, oldY, empty, HEIGHT);
}
**/






return 0;



}
