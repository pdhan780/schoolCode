#include "psg.h"





void write_psg(int reg, UINT8 val)
{

 long old_ssp;

 if(reg >= 0 && reg <= 15)
  {

    old_ssp = Super(0); /*enter supervisor mode*/

    *psgSelect = reg; /*select register to interact with*/

    *psgWrite = val;
 


   Super(old_ssp); /*exit supervisor*/

  }
}




UINT8 read_psg(int reg)
{

    long old_ssp;

    int val = 0;


    old_ssp = Super(0);

    if (reg >= 0 && reg <= 15)

   {


       *psgSelect = reg; /*select register you want to read from*/

       val = *psgSelect;
   }



   Super(old_ssp);

   return val;


}
