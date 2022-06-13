#include <Servo.h> // servo library
Servo myservo;
int m=0;
int pos = 0;
void setup()
{
// put your setup code here, to run once:
pinMode(A0, INPUT_PULLUP);           // Soil Moisture Sensor  PIN A0
pinMode(8,OUTPUT);                             // Relay Module PIN D8
Serial.begin(9600);                                  //  Sensor Buart Rate
myservo.attach(9);                                   //  Servo PIN D9
digitalWrite(8, HIGH);                           // Relay Normally High for OFF condition
}
void loop()
{
// put your main code here, to run repeatedly:
int m= analogRead(A0);                         // Soil Moisture Sensor  PIN A0
Serial.println(m);
delay(200);
if (m>=980)
{
myservo.write(90);              // tell servo to go to position in variable 'pos'

digitalWrite(8, LOW);       // Relay ON
delay(1000);
}
else if(m<=970)
{
digitalWrite(8, HIGH);      // Relay OFF
}
else
{
digitalWrite(8, HIGH);   // Relay OFF
}
}
