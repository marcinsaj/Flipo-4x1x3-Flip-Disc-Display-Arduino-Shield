#include <FlipDisc.h>   // https://github.com/marcinsaj/FlipDisc



#define EN_PIN  10
#define CH_PIN  A0
#define PL_PIN  A1


void setup()
{
  /* Flip.Pin(); it is the most important function and first to call before everything else.
  The function is used to declare pin functions. Before starting the device, double check
  that the declarations and connection are correct. If the connection of the control outputs
  is incorrect, the display may be physically damaged. */
  Flip.Pin(EN_PIN, CH_PIN, PL_PIN);
 
  /* Flip.Init(display1, display2, ... display8); it is the second most important function.
  Initialization function for a series of displays. Up to 8 displays can be connected in series
  in any configuration. The function also prepares SPI. Correct initialization requires
  code names of the serially connected displays:
  - D7SEG - 7-segment display
  - D2X1 - 2x1 display
  - D3X1 - 3x1 display
  - D1X3 - 1x3 display
  - D1X7 - 1x7 display */
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










 
  Flip.Clear();
  delay(1000);
}
