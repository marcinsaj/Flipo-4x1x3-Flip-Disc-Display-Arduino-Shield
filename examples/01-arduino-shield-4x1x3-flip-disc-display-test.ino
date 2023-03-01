/*----------------------------------------------------------------------------------*
 * Arduino Shield for 4 x 1x3 Flip-disc Display - example of display control        *
 *                                                                                  *
 * Project website: https://bit.ly/ARD-4x1x3                                        *
 * Marcin Saj 28 Feb 2023                                                           *
 * https://www.Flipo.io                                                             *
 *                                                                                  *
 * Arduino Nano Every is required                                                   *
 * 1x3 Flip-disc display is required: https://bit.ly/1x3-FD                         *
 *----------------------------------------------------------------------------------*/

#include <FlipDisc.h>   // https://github.com/marcinsaj/FlipDisc

// Pin declaration for Arduino Nano Every and PSPS module
#define EN_PIN  10      // Start & End SPI transfer data
#define CH_PIN  A0      // Charging PSPS module - turn ON/OFF
#define PL_PIN  A1      // Release the current pulse - turn ON/OFF

void setup()
{
  /* The most important function and first to call before everything else.
  Details can be found in the description of the library 
  https://github.com/marcinsaj/FlipDisc */
  Flip.Pin(EN_PIN, CH_PIN, PL_PIN);
 
  /* Initialization function of the displays */
  Flip.Init(D1X3, D1X3, D1X3, D1X3);
  
  delay(3000);
}

void loop()
{
  /* The function is used to turn off (clear) all displays */
  Flip.Clear();
  delay(1000);
 
  /* The function is used to turn on (set) all discs of all displays */
  Flip.All();
  delay(1000);

  Flip.Clear();
  delay(1000);

  FlipDiscRoutine_1();
  FlipDiscRoutine_2();
  FlipDiscRoutine_3();
  FlipDiscRoutine_4();
  
  Flip.All();
  delay(1000);
}

/* Flip.Disc_1x3 function allows you to control a selected disc in a selected D1X3 display.
 * You can control only one disc of the selected display at a time.
 * Flip.Disc_1x3(module_number, discNumber, discStatus);
 * - module_number - relative number of the D1X3 display
 * - discNumber - display disc number counting from left to right 1-3
 * - discStatus - reset disc "0" or set disc "1" 
 * Details can be found in the description of the library https://github.com/marcinsaj/FlipDisc */

void FlipDiscRoutine_1(void)
{
  for (int i = 0; i < 5; i++)
  {
    for(int j = 1; j <= 3; j++)
    {
      Flip.Disc_1x3(1, j, 1);
      Flip.Disc_1x3(2, (3+1)-j, 1);
      Flip.Disc_1x3(3, j, 1);
      Flip.Disc_1x3(4, (3+1)-j, 1);      
      delay(200);  
    }
   
    for(int j = 1; j <= 3; j++)
    {
      Flip.Disc_1x3(1, j, 0);
      Flip.Disc_1x3(2, (3+1)-j, 0);
      Flip.Disc_1x3(3, j, 0);
      Flip.Disc_1x3(4, (3+1)-j, 0);      
      delay(200);  
    }
  }
  
  delay(1000); 
}

void FlipDiscRoutine_2(void)
{
  for(int i = 0; i < 5; i++)
  {
    for(int j = 1; j <=3; j++)
    {
      Flip.Disc_1x3(1, j, 1);
      delay(200);
      Flip.Disc_1x3(2, j, 1);  
      delay(200);
      Flip.Disc_1x3(3, j, 1);
      delay(200);
      Flip.Disc_1x3(4, j, 1);  
      delay(200);      
    }
    for(int j = 1; j <=3; j++)
    {
      Flip.Disc_1x3(1, j, 0);
      delay(200);
      Flip.Disc_1x3(2, j, 0);  
      delay(200);
      Flip.Disc_1x3(3, j, 0);
      delay(200);
      Flip.Disc_1x3(4, j, 0);  
      delay(200);      
    }
  }
}

void FlipDiscRoutine_3(void)
{
  for(int i = 0; i < 5; i++)
  {
    for(int j = 1; j <=3; j++)
    {
      Flip.Disc_1x3(1, j, 1);
      Flip.Disc_1x3(2, j, 0);
      Flip.Disc_1x3(3, j, 1);
      Flip.Disc_1x3(4, j, 0);
    }
   
    delay(1000);
   
    for(int j = 1; j <=3; j++)
    {
      Flip.Disc_1x3(1, j, 0);
      Flip.Disc_1x3(2, j, 1);
      Flip.Disc_1x3(3, j, 0);
      Flip.Disc_1x3(4, j, 1);
    }

    delay(1000);
  }
}

void FlipDiscRoutine_4(void)
{
  for(int i = 0; i < 5; i++)
  {
    for(int j = 3; j >= 1; j--)
    {
      Flip.Disc_1x3(1, j, 1);
      Flip.Disc_1x3(2, j, 1);
      Flip.Disc_1x3(3, j, 1);
      Flip.Disc_1x3(4, j, 1);
      delay(200);
    }
    for(int j = 1; j <=3; j++)
    {
      Flip.Disc_1x3(1, j, 0);
      Flip.Disc_1x3(2, j, 0);
      Flip.Disc_1x3(3, j, 0);
      Flip.Disc_1x3(4, j, 0);
      delay(200);
    }
  }
}
