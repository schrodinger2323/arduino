//devre üzerinde iki tane 330 ohmluk direnci seri bağladık.. 5v pinine
//daha sonra A3 analog pini ile belli noktaların voltaj değerlerini izledik serial monitor ile
// analogRead 0 ile 1023 arasında bir değer döndürür... 
//gercek   analogRead
//0V           ~0
//2.5V         ~512
//5V           ~1023  degerlerini verecektir/
int readPin=A3;
int V2=0;
int delayTime=500;
void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  V2=analogRead(readPin);
  Serial.println(V2);
  delay(delayTime);
}
