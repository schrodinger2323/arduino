//potansiyometreden okuduğumuz voltaj değeri(x):
//x<3 ise gLed on others off
//x>3 && x<4 ise yLed on others off
//x>4 ise rLed on others off
int readVal;
float V2;
int rLed=4; //red LED
int yLed=8; //yellow LED
int gLed=12; //green LED
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rLed, OUTPUT);
  pinMode(yLed, OUTPUT);
  pinMode(gLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal=analogRead(A2);
  V2=(5./1023.)*readVal;

  Serial.println(V2);

  if(V2 <3){
   digitalWrite(rLed, 0);
   digitalWrite(yLed, 0);
   digitalWrite(gLed, 1);
  }
  else if(V2>3 && V2<4){
   digitalWrite(rLed, 0);
   digitalWrite(yLed, 1);
   digitalWrite(gLed, 0);
  }
  else{
   digitalWrite(rLed, 1);
   digitalWrite(yLed, 0);
   digitalWrite(gLed, 0);
  }
  delay(250);
}
