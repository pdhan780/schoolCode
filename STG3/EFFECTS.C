#include "effects.h"


void move_effect()
{

int volume = 11;

int sustain = 10;



/*effects on channel B = 1*/


set_tone(1, 248);

set_envelope(7,sustain);

enable_channel(1,true,false);

set_volume(1, volume);


}



void explosion_effect()
{


  int volume = 11;

  int sustain = 10;



  /*effects on channel B = 2*/
  set_envelope(7, sustain);

  enable_channel(1, false, true);

  set_volume(1, volume);

  

}
