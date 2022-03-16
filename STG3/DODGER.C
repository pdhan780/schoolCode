#include <osbind.h>


#include "render.h"
#include "raster.h"
#include "model.h"
#include "events.h"
#include "types.h"

#define HEIGHT 16
#define WIDTH 640
#define SCREEN_HEIGHT 400
#define LEFT_ARROW 0x004B0000
#define RIGHT_ARROW 0x004D0000
#define CLEAR_INPUT 0x00000000

typedef unsigned long ULONG32;

ULONG32 get_time();

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


int main(){


UINT16 *base = (UINT16 *) Physbase();


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


struct Model *modelPtr = &gameModel; /*ptr for game objects in model*/

unsigned int oldX;
unsigned int oldY;
int colLevel = 1;
int rowLevel = 0;
bool gameCrash = false;
bool hitBottom;
long userInput;

ULONG32 timeThen, timeNow, timeElapsed;/*keep track of time*/


clear_screen(base,WIDTH,SCREEN_HEIGHT);

/*render the model, the first frame*/
render(modelPtr, base, spaceship_bitmap, asteroid_bitmap, colLevel, rowLevel);

timeThen = 0;

/************* game loop ********/
while (gameCrash == false) {

hitBottom = false;

timeNow = get_time();


if (Cconis())

{

    userInput = Cnecin();


     if(userInput == LEFT_ARROW)
   {

       modelPtr->gameShip.deltaX = -1;
       move_spaceship( &(modelPtr->gameShip));
    }
	

     if(userInput == RIGHT_ARROW)

    {
		
      modelPtr->gameShip.deltaX = 1;		
      move_spaceship( &(modelPtr->gameShip));
				
     }

}


   timeElapsed = timeNow - timeThen;


       if(timeElapsed = 140)

      {

        /*render the updated model*/
		/*do proper rendering procedure, (old coords)*/
		/*check for collision*/
		
       




        timeThen = timeNow;

     }
		

      /* check if asteroid hit bottom*/


        hitBottom =	  
		
      user_input = CLEAR_INPUT;


      
}



/*check only when one asteroid hits bottom to signal wave over*/


return 0;



}



ULONG32 get_time() {

long currTime;

long *timer =(long *)0x462;

long old_ssp;  /*begin entering privelleged mode for timer mem location*/

old_ssp = Super(0);

currTime = *timer; /*grab the time*/

Super(old_ssp); /*exit privelleged mode */

(ULONG32)currTime;

return currTime;

}




