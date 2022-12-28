int ledPin =  13;// the number of the LED pin
// delay mem
int delayTime15 = 15;
int delayTime45 = 45;
int motionState = ;


/*
 * PIR sensor tester
 */
 
int ledPin = 13;                // choose the pin for the LED
int pirPin = 2;               // choose the input pin (for PIR sensor)
int remotePinA = ; // choose remote opt A
int remotePinB = ; // choose remote opt B 
int remotePinC = ; // choose remote opt C

int pirState = LOW;             // we start, assuming no motion detected
int remoteState = LOW;
int 
int valRemote = 0;
int valMotion = 0;
int val = 0;
  


// Variables will change :
int ledState = LOW;  

// obj_struct 
void setup() 
{
    pinMode(ledPin, OUTPUT);      // declare LED as output
    pinMode(inputPin, INPUT);     // declare sensor as input
    Serial.begin(9600);
}

void loop() 
{
  val = digitalRead(inputPin);  // read input value
  // check if the input is HIGH
  if (val == HIGH) 
  {            
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) 
    {
        // we have just turned on
        Serial.println("Motion detected!");
        // We only want to print on the output change, not state
        pirState = HIGH;
    }
  } 
  else 
  {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH)
    {
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
