/**
Main Game with main game loop

Authors: Pelvain Dhanda, Nimrit Brar


**/



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
#define BUFFSIZE 32256
#define CLOCKCHECK 5

typedef unsigned long ULONG32;

UINT8 secondBuffer[BUFFSIZE];

ULONG32 get_time();

UINT8* get_base(UINT8 *secondBuffer);



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


struct Model gameModel = 
{

    {224, 250, 6 , 16, 16, 0 }, /*single spaceship instance */

{

  {

    {10, 0, 10, 16, 16, 10 },   /*beginning of wave 1*/

    {300, 0 ,10 , 16, 16, 11}

  },


  {

    {15, 0, 5, 16, 16,10}, /*beginning of wave 2*/

    {55, 0, 5, 16, 16, 40},

    {375 ,0, 5, 16, 16, 38},

    {450, 0, 5, 16, 16, 55}

  },

{

    {1, 0, 10, 16, 16, 25}, /*beginning of wave 3*/

    {50, 0, 10, 16, 16, 48},

    {90, 0, 10, 16, 16, 33},

    {250, 0 , 10 , 16, 16,60},
    
    {400, 0, 10, 16, 16, 65},

    {450, 0, 10 , 16, 16, 70}     
     
},


{
    {1, 0, 10, 16, 16,10}, /*beginning of wave 4*/

    {50, 0, 10, 16, 16, 20},
	
    {100, 0, 10, 16, 16, 30},

    {250, 0 , 10 , 16, 16, 68},
    
    {400, 0, 10 , 16, 16, 39},
   
    {450, 0, 10 , 16, 16, 50},     
     
    {500, 0, 10, 16, 16, 40},

    {600, 0, 10, 16, 16, 85}


},



{                           

  

   {1, 0, 20, 16, 16, 16},        /*beginning of wave 5*/

   {50, 0, 20, 16, 16, 20},

   {100, 0, 20, 16, 16, 70},

   {250, 0 , 20 , 16, 16, 67},
    
   {400, 0, 20 , 16, 16, 19},
   
   {450, 0, 20 , 16, 16, 20},     
     
   {540, 0, 20, 16, 16, 36},

   {595, 0, 20, 16, 16, 48},

   {600, 0, 20, 16, 16, 50},

   {630, 0, 20, 16, 16, 80}

},


{

   {1, 0, 25, 16, 16, 18},        /*beginning of wave 6*/

   {50, 0, 25, 16, 16, 56},

   {100, 0, 25, 16, 16, 20},

   {150, 0, 25, 16, 16, 28},

   {200, 0, 25, 16, 16, 30},

   {250, 0 , 25 , 16, 16, 47},
    
   {300, 0, 26 , 16, 16, 55},
   
   {450, 0, 25 , 16, 16, 38},     
     
   {540, 0, 25, 16, 16, 29},

   {595, 0, 25, 16, 16, 60},

   {615, 0, 30, 16, 16, 70},

   {630, 0, 45, 16, 16, 90}


   
},


 {

   {1, 0, 46, 16, 16, 20},
                           /*beginning of wave 7*/
   {30, 0, 45, 16, 16, 30},
      
   {50, 0, 2, 16, 16, 30},

   {100, 0, 2, 16, 16, 38},

   {150, 0, 2, 16, 16, 28},

   {200, 0, 2, 16, 16, 45},

   {250, 0 , 2 , 16, 16, 70},
    
   {300, 0, 2 , 16, 16, 56},
  
   {350, 0, 2, 16, 16, 56},
 
   {450, 0, 2 , 16, 16, 49},     
     
   {540, 0, 2, 16, 16, 78},

   {595, 0, 2, 16, 16, 37},

   {615, 0, 2, 16, 16, 48},

   {640, 0, 2, 16, 16, 95}


 },


  {


   {0, 0, 2, 16, 16, 30},
                           /*beginning of wave 8*/
   {32, 0, 2, 16, 16, 31},
      
   {64, 0, 2, 16, 16, 33},

   {96, 0, 2, 16, 16, 55},

   {128, 0, 2, 16, 16, 54},

   {160, 0, 2, 16, 16, 78},

   {192, 0 , 2 , 16, 16, 60},
    
   {224, 0, 2 , 16, 16, 58},
  
   {256, 0, 2, 16, 16, 80},
 
   {288, 0, 2 , 16, 16, 85},     
     
   {320, 0, 2, 16, 16, 77},

   {352, 0, 2, 16, 16, 51},

   {384, 0, 2, 16, 16, 52},

   {416, 0, 2, 16, 16, 76},

   {448, 0 , 2, 16, 16, 80},

   {480, 0, 2, 16, 16, 89}


  },


{

   {0, 0, 1, 16, 16, 40},
                           /*beginning of wave 9*/
   {32, 0, 1, 16, 16, 42},
      
   {64, 0, 1, 16, 16, 44},

   {96, 0, 1, 16, 16, 60},

   {128, 0, 1, 16, 16, 18},

   {160, 0, 1, 16, 16, 27},

   {192, 0 , 1 , 16, 16, 16},
    
   {224, 0, 1 , 16, 16, 33},
  
   {256, 0, 1, 16, 16, 39},
 
   {288, 0, 1 , 16, 16, 45},     
     
   {320, 0, 1, 16, 16, 78},

   {352, 0, 1, 16, 16, 22},

   {384, 0, 1, 16, 16, 27},

   {416, 0, 1, 16, 16, 100},

   {448, 0 , 1, 16, 16, 98},

   {480, 0, 1, 16, 16, 72},

   {512, 0, 1, 16, 16, 65},
    
   {544, 0, 1, 16, 16, 108}

 
  },


{

  
   {0, 0, 1, 16, 16, 30},
                           /*beginning of wave 10*/
   {32, 0, 1, 16, 16, 75},
      
   {64, 0, 1, 16, 16, 77},

   {96, 0, 1, 16, 16, 78},

   {128, 0, 1, 16, 16, 85},

   {160, 0, 1, 16, 16, 80},

   {192, 0 , 1 , 16, 16, 63},
    
   {224, 0, 1 , 16, 16, 40},
  
   {256, 0, 1, 16, 16, 20},
 
   {288, 0, 1 , 16, 16, 23},     
     
   {320, 0, 1, 16, 16, 30},

   {352, 0, 1, 16, 16, 16},

   {384, 0, 1, 16, 16, 81},

   {416, 0, 1, 16, 16, 22},

   {448, 0 , 1, 16, 16, 13},

   {480, 0, 1, 16, 16, 12},

   {512, 0, 1, 16, 16, 5},
    
   {544, 0, 1, 16, 16, 3},

   {576, 0, 1, 16, 16, 17},

   {608, 0 , 1,16, 16, 98}


  }

 } /*end of 2D wave array */

}; /*end of model struct*/


int main(){


UINT16 *base = (UINT16*) Physbase();


UINT16 *base2 = (UINT16*) get_base(secondBuffer); /*get address */ 

                                                    
struct Model *modelPtr = &gameModel; /*ptr for game objects in model*/



int x;
         /*x and x2 are counters for wave operations*/
int x2;


int colLevel = 1;/*initial row and column levels*/
int rowLevel = 0;

bool gameCrash = false; /*game over crash*/
bool hitBottom = false;/* asteroid bottom boundry crash*/
int screenCheck = 0;

long userInput; /*store keyboard scancode*/

ULONG32 timeThen, timeNow, timeElapsed;/*keep track of time*/


/*clear the screen for game-setup */

/*render the model, the first frame*/

clear_screen(base, WIDTH, SCREEN_HEIGHT);

clear_screen(base2, WIDTH, SCREEN_HEIGHT);

render(modelPtr, base, spaceship_bitmap, asteroid_bitmap, colLevel, rowLevel);

timeThen = 0;




while (gameCrash == false && rowLevel <= 9) {



hitBottom = false;


timeNow = get_time();


if (Cconis())

{

     userInput = Cnecin();


     if(userInput == LEFT_ARROW)

   {
     
       modelPtr->gameShip.direction = -1;
    }
	

     if(userInput == RIGHT_ARROW)

    {

       modelPtr->gameShip.direction = 1;     
				
     }

}


timeElapsed = timeNow - timeThen;


     if(timeElapsed > CLOCKCHECK )

  {

      for (x = 0; x <= colLevel; x++)
    {
        
		
        if( modelPtr->asteroids[rowLevel][x].delayTime != 0)
	
        {
		
	
	    modelPtr->asteroids[rowLevel][x].delayTime--;
						
	 }
		
		
	 else

	  {
					
	    move_asteroid( &(modelPtr->asteroids[rowLevel][x]));
							
		

	  }


    }	

    moveSafe( &(modelPtr->gameShip));   	 	 
		
    gameCrash = collision_detect_fleet(modelPtr, colLevel, rowLevel);

    timeThen = timeNow;

       if (screenCheck == 0)
     {
	  					
          render(modelPtr, base2, spaceship_bitmap, asteroid_bitmap, 
               colLevel, rowLevel);
			     			   
	      Setscreen(-1, base2, -1);

          Vsync();
	   
          clear_screen(base, WIDTH, SCREEN_HEIGHT);
			
	     screenCheck = 1;
		  
					
       }
     


       if (screenCheck == 1)
    {
		
         render(modelPtr, base, spaceship_bitmap, asteroid_bitmap, 
               colLevel, rowLevel);
	 
		   
         Setscreen(-1, base, -1);

         Vsync();
          
         clear_screen(base2, WIDTH, SCREEN_HEIGHT);		  
			
         screenCheck = 0;	
			
			
     }



  } 


		
       for( x2 = 0; x2 <= colLevel; x2++) /*check last asteroid and move on*/

     {    

         hitBottom = bottomCrash(&(modelPtr->asteroids[rowLevel][x2]));
        
        
      }

		
       if(hitBottom == true)

      {

          rowLevel = rowLevel + 1;
          colLevel = colLevel + 2;

      }			
      
             
} 


       if (screenCheck == 0)

	{
		   
            Setscreen(-1, base, -1);
			 
            Vsync();
		   
		   
		   
	 }






return 0;



}

/**
Helper Function get_time
returns the current clock time
so clocked events may occur
**/

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


/**
get_base allows
for the second buffer
to start at correct address
in memory
**/

UINT8 *get_base(UINT8 *second_buffer) {
	
  UINT8 *base;

  UINT16 difference;

  base = second_buffer;

  difference = (int) base;

  difference %= 0x100;

  difference = 0x100 - difference;

  return base + difference;
  
}




