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

    int val = -1;


    old_ssp = Super(0);

    if (reg >= 0 && reg <= 15)

   {


       *psgSelect = reg; /*select register you want to read from*/

       val = *psgSelect;
   }
  
      Super(old_ssp);

      return val;
}

/*0 = A, 1 = B, 2 = C*/
void set_volume(int channel, int volume)
{
   
   if (channel == 0)
   {
	   
	   write_psg(CH_A_VOL, volume);
   }

   if (channel == 1)
   {
	   
	   write_psg(CH_B_VOL, volume);
	   
   }
   
   
   if (channel == 2)
   {
	   
	  write_psg(CH_C_VOL, volume);
	   
   }


}	


void set_tone(int channel, int tuning)
{
	
	
	if (channel == 0)
	{
	  	
   	  write_psg(CH_A_TONE, tuning);
	}
	
	
	
	if (channel == 1)
	{
		
	   write_psg(CH_B_TONE, tuning);
	}
	
	
	
	if (channel == 2)
		
        {
	
	  write_psg(CH_C_TONE, tuning);
			
			
	}
	
	
}

/**
enable the selected channel with noise, tone, or both
**/

void enable_channel(int channel, bool tone_on, bool noise_on)
{
	
  bool tone_only = tone_on && !noise_on;
  
  bool noise_only = !tone_on && noise_on;
  
  bool tone_and_noise = tone_on && noise_on;
  
  int existing_mixer_val = read_psg(MIXER_REG);
  
  int channelValue;
  
  
  if (channel == 0)
  {
	  
	 if (tone_only)
	 {

        channelValue = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_TONE_CH_A : MIXER_TONE_CH_A;

	 }		 
	  
	  
	else if (noise_only)
	{

     channelValue = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_NOISE_CH_A : MIXER_NOISE_CH_A;


	}


    else if (tone_and_noise)
	{
      channelValue = existing_mixer_val != -1 ?
                     existing_mixer_val & (MIXER_TONE_CH_A & MIXER_NOISE_CH_A):
                      (MIXER_TONE_CH_A & MIXER_NOISE_CH_A);

	}		
	  
	  
	  
  }
  
  
  
  
  
  if (channel == 1)
  {
	  
	if (tone_only)
	 {

        channelValue = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_TONE_CH_B : MIXER_TONE_CH_B;

	 }		 
	  
	  
	else if (noise_only)
	{

     channelValue = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_NOISE_CH_B : MIXER_NOISE_CH_B;


	}


    else if (tone_and_noise)
	{
      channelValue = existing_mixer_val != -1 ?
                     existing_mixer_val & (MIXER_TONE_CH_B & MIXER_NOISE_CH_B):
                      (MIXER_TONE_CH_B & MIXER_NOISE_CH_B);

	}	  
	  
	  
	  
	  
	  
  }
  
   
  if (channel == 2)
  {
	  
	  
		if (tone_only)
	 {

        channelValue = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_TONE_CH_C : MIXER_TONE_CH_C;

	 }		 
	  
	  
	else if (noise_only)
	{

     channelValue = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_NOISE_CH_C : MIXER_NOISE_CH_C;


	}


    else if (tone_and_noise)
	{
      channelValue = existing_mixer_val != -1 ?
                     existing_mixer_val & (MIXER_TONE_CH_C & MIXER_NOISE_CH_C):
                      (MIXER_TONE_CH_C & MIXER_NOISE_CH_C);

	}	   
	  
	  
	 	  
  }
  
  
     write_psg(MIXER_REG, channelValue);
}  
	
	
	
 /**

stop all noise production
turn off all bits
**/ 
 void stop_sound()
 {

  write_psg(MIXER_REG, 0x00);
  write_psg(NOISE_FREQUENCY_REG, 0x00);
  write_psg(ENVELOPE_FINE_REG, 0x00);
  write_psg(ENVELOPE_ROUGH_REG, 0x00);
  write_psg(ENVELOPE_SHAPE_CONTROL_REG, 0x00);

  set_volume(0, 0); /*stop volume for all channels*/
  set_volume(1, 0);
  set_volume(2, 0);

 }	 



void set_envelope(int shape, unsigned int sustain)
{
	
  int shapeValue;
  write_psg(ENVELOPE_FINE_REG, sustain);
  write_psg(ENVELOPE_ROUGH_REG, sustain);
	
	
  if (shape == 0)
  {

     shapeValue = ENV_SAW_SHAPE;
  }	


  if (shape == 1)
  {
     shapeValue = ENV_SAW_SHAPE;

  }	  
	
  if (shape == 2)
  {

     shapeValue = ENV_SAW_SHAPE_INV;
  }

  if(shape == 3)
  {
    shapeValue = ENV_SAW_PERIOD_SHAPE;

  }	
	
	
  if (shape == 4)
 {

    shapeValue = ENV_TRIANGLE_SHAPE;
 }


  if(shape == 5)

  {

    shapeValue = ENV_TRIANGLE_INV_SHAPE;
	
  }


  if(shape == 6)


  {
	
    shapeValue = ENV_TRIANGLE_PERIOD_SHAPE;
	
  }


  if(shape == 7)
	
 {
    shapeValue = ENV_TRIANGLE_INV_PERIOD_SHAPE;		
		
 }	
	
	
	
}




void set_noise(int tuning)

{
	
  write_psg(NOISE_FREQUENCY_REG, tuning);
	
	
}
  



