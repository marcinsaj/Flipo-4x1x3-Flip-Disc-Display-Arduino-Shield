/*----------------------------------------------------------------------------------*
 * Arduino Shield for 4 x 1x3 Flip-disc Display - buttons & display control         *
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







/* To do */
