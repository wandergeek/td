/* 
Basic use of controlVoltage library to implement a trigger and ramp CV
- trigger duration is 3ms by default
- the ramp CV is updated at the same time as the trigger (100ms interval)
- uses cv(val, rampTime) to smooth the transition between CV values
- basically, a slew limiter

This example uses the built-in DAC on the ESP32 as output

Monitor in Arduino's serial plotter
*/

#include <controlVoltage.h>

//define cv objects
controlVoltage chan2 = controlVoltage(); //trigger

const byte dac2 = 26;

void setup(){
  Serial.begin(115200);  // initialize serial interface for print()

  chan2.bitDepth( 8 );
}


void loop(){
  chan2.loop();

  if (Serial.available() > 0) {
    int valA = Serial.parseInt();
    Serial.print("I received: ");
    Serial.println(valA);
    chan2.trigger();
  }
  
  static uint32_t signalTimer = 0;
  int signalInterval = 5;
  if(millis()-signalTimer >= signalInterval){
    uint16_t trigVal = chan2.get();
    dacWrite(DAC2, trigVal );
    signalTimer = millis();
  }
}
