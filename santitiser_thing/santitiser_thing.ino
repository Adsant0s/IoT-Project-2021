int soundSensor=2;
int buzzer=4;
boolean LEDStatus=false;
int counter =0;
void setup() {
 pinMode(soundSensor,INPUT);

 
 int SensorData=digitalRead(soundSensor); 
 
while(counter != 1)
{
if(SensorData==1)
{
 tone(buzzer, 600 );
    delay(500);
counter++;
}
}
counter =0;
}
