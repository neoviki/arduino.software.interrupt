#include "TimerOne.h"

/*Software interrupt will be triggered every 500000 microseconds*/
#define INTERRUPT_INTERVAL 500000

int interrupt_counter = 0;

void init_interrupt()
{
  Timer1.initialize(INTERRUPT_INTERVAL); 
  Timer1.attachInterrupt( interrupt_handler ); 
}

void setup() 
{
  init_interrupt();
  Serial.begin(9600);
}

void loop() {
  Serial.print("Interrupt Counter = ");
  Serial.println(interrupt_counter);
}

/*Interrupt Service Routine
 * 
 * interrupt_handler best practice:
 *    - interrupt_handler does not take any arguments
 *    - interrupt_handler does not return anything
 *    - interrupt_handler should execute small piece of code
 *    - Do not call another interrupt inside interrupt_handler
 */
void interrupt_handler()
{
  interrupt_counter++;
}
