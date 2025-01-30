int readPin=A3;
float V2=0;
int delayTime=500;
int readVal;
void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal=analogRead(readPin);//readVal=0..1023
  V2=(5./1023.)*readVal;//V2=0V..5V bu sayede monitorde gercek voltaj degerlerini gorebiliriz...
  Serial.println(V2);
  delay(delayTime);
}
