int photoResistorPin=A1;
int led=11;
int counter = 0;
float sum = 0;
float avg = 0.0;
float out = 255 - (avg-560) * 255 / 463;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(photoResistorPin,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  float out = 255 - avg * 255 / 463;
 
 
  counter ++;
  
  int val = analogRead(photoResistorPin);
  if(counter <=100)
  {
    sum += val;
    if(counter = 100)
    avg=sum/100.0;
  }
  else if (counter > 100)
  {
    avg = avg * 0.99 + val * 0.01;
  }
  
  

  Serial.println(avg);

  analogWrite(led, out);
  delay(100);

  if ( val < 800 )
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  
}
