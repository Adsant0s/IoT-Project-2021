/*
Derived from Yún HTTP Client Sketch
 This example for the Arduino Yún shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.
 created by Tom igoe
 May 2013
 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/HttpClient
 Additions added by Mary Loftus April 2018 
 - adapted from example by Tom DeBell - August 2017 - http://www.open-sensing.org/evaporometerblog/datalog
 */


  /////////////////
 // MODIFY HERE //
/////////////////

// Add your PushingBox Scenario DeviceID here:
  char devid[] = "v3673ABB754A87E4"; 

  const int sensor =5;
   const int buzzer =4;
  const int button =3; 
  

   
  
int buttonState =0;
 
  //////////////
 //   End    //
//////////////

char serverName[] = "api.pushingbox.com";
boolean DEBUG = true;
#include <Bridge.h>
#include <HttpClient.h>

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);


pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT); 


  Serial.begin(9600);
  while (!Serial); // wait for a serial connection
}

void loop() {
  //buttonState = digitalRead(buttonPin);
  buttonState = digitalRead(sensor); 
  int buttonPressed = digitalRead(button);
   // Initialize the client library
  HttpClient client;


if(buttonState == HIGH)
 {
  //Setup sensorValue to read a value from Analog Port A0
int sensorValue = 0;
int sensorValue2=0;

  
  //Serial.print("start");
  
  do{digitalWrite(buzzer, HIGH);
    buttonPressed = digitalRead(button);     
    if(buttonState == HIGH)
    {        
      sensorValue2 = analogRead(A0); 
      
    }
    } while (buttonPressed == LOW);
    delay(100);
    
    
   
    
  
     
      sensorValue = analogRead(A0);
      
 
  
  //Testing value - when sensor is not connected - comment out when sketch is shown to be working - and take value from A0 instead
  //sensorValue=1500;

  



  // Make a HTTP request:  
  String APIRequest;
  APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid)+ "&IDtag="+sensorValue2+"&TimeStamp=50&TempC="+1;
  client.get (APIRequest);
  
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();

  }
 
  Serial.flush();
  String UploadMessage;
  Serial.print("\n Uploaded temp value: "); 
  Serial.print(sensorValue);
  Serial.print("\n Uploaded Second Value: ");
  
  Serial.print(sensorValue2);
  delay(100);
 
 }
else{
  digitalWrite(buzzer,LOW);
}
 
}
