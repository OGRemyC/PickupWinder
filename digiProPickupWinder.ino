/*
Pickup winder control software
Working:
- High frequency (PWM 64kHz) speed control
  - Configure Timer/Counter1 registers via TCCR1A and TCCR1B bit shift commands. 
  - (False lead)Set MS_TIMER_TICK_EVERY_X_CYCLES in /home/remy/.arduino15/packages/digistump/hardware/avr/1.6.7/cores/tiny/wiring.c
- Single Darlington transistor control
- Open loop speed set by potentionmeter
Pending:
- H-bridge control
- Isolation
- Pulse counter
- RPM calculation
- RPM PID control
*/


int motorPin = 1; //Output to Darlington gate
int controlPin = 3; //Input from control pot wiper, physical pin 9 = analog 3
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT); //
  pinMode(controlPin, INPUT);

  #define TIMER_TO_USE_FOR_MILLIS = 0; //Use timer 0 because timer 1 configured for fast PWM
//  TCCR1B = (TCCR1B & 0b11111000) | 0x01;
//  TCCR1B = TCCR1B & B11111000 | B00000001;
//
//  //Configure TCCR1 registers for Fast PWM with TOP=OCR1A, freq prescale 1
//  TCCR1A = _BV(WGM11) | _BV(WGM10);
//  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);

  //Configure TCCR1 registers for Fast PWM with TOP=0x00FF (255), freq prescale 1
  TCCR1A |= _BV(COM1A1) | _BV(COM1A0) | _BV(WGM10); //| _BV(WGM11) | _BV(COM1A1) | _BV(COM1A0) | 
  TCCR1B |= _BV(WGM12) | _BV(CS10); //_BV(WGM13) | _BV(CS11) | 
  
} 
 
 
void loop() 
{  
  int speed = analogRead(controlPin);
  speed = speed/4;
  
  if (speed >= 0 && speed <= 255)
  {
    analogWrite(motorPin, speed);
  }

////Analog Input test
//  int test = analogRead(3);
//  if (test > 512)
//  {
//    digitalWrite(motorPin, HIGH);
//  }
//  else
//  {
//    digitalWrite(motorPin, LOW);
//  }

//PWM test
//  analogWrite(motorPin, 100);
//  delay(2000);
//  analogWrite(motorPin, 0);
//  delay(3000);
//  analogWrite(motorPin, 200);
//  delay(5000);
//  analogWrite(motorPin, 0);
//  delay(1000);

} 
