// NuMechRon design by Victorrr161 https://www.thingiverse.com/thing:2381829 
// Conversion for Arduino Nano and stepperboard ULN2003A by Jeroen Jonkman, 30/12/2017

// Wiring:
// Connect pin GND of the Arduino to pin GND of the stepper board
// Connect pin 5V of the Arduino to pin VCC of the stepper board
#define OUT1  A1 // Connect pin A1 of the Arduino to pin IN4 of the stepper board
#define OUT2  A2 // Connect pin A2 of the Arduino to pin IN3 of the stepper board
#define OUT3  A3 // Connect pin A3 of the Arduino to pin IN2 of the stepper board
#define OUT4  A4 // Connect pin A4 of the Arduino to pin IN1 of the stepper board

int countStep = 0; // Initialize countStep

void setup() // Handle setup
{
  pinMode(OUT1, OUTPUT); // Use A1 as a digital output
  pinMode(OUT2, OUTPUT); // Use A2 as a digital output
  pinMode(OUT3, OUTPUT); // Use A3 as a digital output
  pinMode(OUT4, OUTPUT); // Use A4 as a digital output
}

void loop() // Handle loop
{
  stepping(); // Call stepping
  delayMicroseconds(30943);  // Pause loop, use value of 30943 for timekeeping or 1000 for testing at high speed
}

void stepping() // Handle stepping
{
  switch(countStep) // Handle each step of countStep
  {
   case 0:
     digitalWrite(OUT1, LOW); 
     digitalWrite(OUT2, LOW);
     digitalWrite(OUT3, HIGH);
     digitalWrite(OUT4, HIGH);
   break; 
   case 1:
     digitalWrite(OUT1, LOW); 
     digitalWrite(OUT2, LOW);
     digitalWrite(OUT3, HIGH);
     digitalWrite(OUT4, LOW);
   break; 
   case 2:
     digitalWrite(OUT1, LOW); 
     digitalWrite(OUT2, HIGH);
     digitalWrite(OUT3, HIGH);
     digitalWrite(OUT4, LOW);
   break; 
   case 3:
     digitalWrite(OUT1, LOW); 
     digitalWrite(OUT2, HIGH);
     digitalWrite(OUT3, LOW);
     digitalWrite(OUT4, LOW);
   break; 
   case 4:
     digitalWrite(OUT1, HIGH); 
     digitalWrite(OUT2, HIGH);
     digitalWrite(OUT3, LOW);
     digitalWrite(OUT4, LOW);
   break; 
   case 5:
     digitalWrite(OUT1, HIGH); 
     digitalWrite(OUT2, LOW);
     digitalWrite(OUT3, LOW);
     digitalWrite(OUT4, LOW);
   break; 
     case 6:
     digitalWrite(OUT1, HIGH); 
     digitalWrite(OUT2, LOW);
     digitalWrite(OUT3, LOW);
     digitalWrite(OUT4, HIGH);
   break; 
   case 7:
     digitalWrite(OUT1, LOW); 
     digitalWrite(OUT2, LOW);
     digitalWrite(OUT3, LOW);
     digitalWrite(OUT4, HIGH);
   break; 
   default:
     digitalWrite(OUT1, LOW); 
     digitalWrite(OUT2, LOW);
     digitalWrite(OUT3, LOW);
     digitalWrite(OUT4, LOW);
   break; 
  }
   
   countStep=countStep+1; // After each cycle add 1 to countStep
   if(countStep==8)
     {countStep=0;} // Reset countStep on rollover
}
