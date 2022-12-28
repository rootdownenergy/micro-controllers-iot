// constants
const int ledP = 11;

boolean f1 = false;

// vars

void setup() 
{
  pinMode(ledP, OUTPUT);
  digitalWrite(ledP, LOW);
  Serial.begin(9600);
}

void loop() 
{
  int inX = 4;
  do
  {
    for (int i=0; i <= 3; i++)
    {
      digitalWrite(ledP, HIGH);
      delay(5000);
      inX = i;
    }
    if(inX == 4)
    {
      digitalWrite(ledP, LOW);
    }
  } while(inX < 3);
  
  if(f1 == true)
  {
    digitalWrite(ledP, LOW);
  }
}
