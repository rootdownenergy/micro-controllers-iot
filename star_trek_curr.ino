const int r1 = 7; //open
const int r2 = 4; //close
const int btnR = 23;
const int btnF = 30;
const int btnU = 37;
const int btnL = 44;
const int btnOpen = 51;
const int ledLock = 25;
const int unlockFlag = 47;
//const int pir = 1;
//const int ledIn = LED_BUILTIN;
//int ledState = LOW;

void setup()
{
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(btnR, INPUT);
  pinMode(btnF, INPUT);
  pinMode(btnU, INPUT);
  pinMode(btnL, INPUT);
  //pinMode(pir, INPUT_PULLUP);
  pinMode(ledLock, OUTPUT);
  //pinMode(ledIn, OUTPUT);
  pinMode(unlockFlag, INPUT_PULLUP);
  pinMode(btnOpen, INPUT);
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  //digitalWrite(pir, HIGH);
  Serial.begin(9600);
}
void loop()
{
  // locals
  int btnRState = digitalRead(btnR);
  int btnFState = digitalRead(btnF);
  int btnUState = digitalRead(btnU);
  int btnLState = digitalRead(btnL);
  int btnOpenState = digitalRead(btnOpen); 
  if(btnRState == HIGH)
  {
    if(digitalRead(r2) == HIGH)
    {
      digitalWrite(r2, LOW);
      delay(1000);
      //open with relay channel 1
      digitalWrite(r1, HIGH);
      delay(5000);
      digitalWrite(r1, LOW);
      delay(5000);
      //auto close after delay
      digitalWrite(r2, HIGH);
    }
    else
    {
      digitalWrite(r2, LOW);
      //open with relay channel 1
      digitalWrite(r1, HIGH);
      delay(1000);
      digitalWrite(r1, LOW);
      delay(4000);
      //auto close after delay
      digitalWrite(r2, HIGH);
    }
  }
  
  if(btnFState == HIGH)
  {
    if(!digitalRead(unlockFlag) == HIGH)
    {
      if(digitalRead(r2) == HIGH)
      {
        digitalWrite(r2, LOW);
        delay(1000);
        //open with relay channel 1
        digitalWrite(r1, HIGH);
        delay(5000);
        digitalWrite(r1, LOW);
        delay(5000);
        //auto close after delay
        digitalWrite(r2, HIGH);
      }
      else
      {
        //open with relay channel 1
        digitalWrite(r1, HIGH);
        delay(5000);
        digitalWrite(r1, LOW);
        delay(5000);
        //auto close after delay
        digitalWrite(r2, HIGH);
      }
    }
  }
  if(btnUState == HIGH)
  {
    if(digitalRead(r1) == HIGH)
    {
      digitalWrite(r1, LOW);
      // set flag to false
      digitalWrite(unlockFlag, LOW);
      digitalWrite(ledLock, LOW);
    }
    if(digitalRead(r2) == HIGH)
    {
      digitalWrite(r2, LOW);
      // set flag to false
      digitalWrite(unlockFlag, LOW);
      digitalWrite(ledLock, LOW);
    }
  }
  if(btnLState == HIGH)
  {
    digitalWrite(unlockFlag, HIGH);
    digitalWrite(ledLock, HIGH);
  }
  if(btnOpenState == HIGH)
  {
    //check to see if the close feature is active
    if(digitalRead(r2) == HIGH)
    {
      digitalWrite(r2, LOW);
      delay(1000);
      digitalWrite(r1, HIGH);
    }
    else
    {
     digitalWrite(r1, HIGH);
    }
  }
}
