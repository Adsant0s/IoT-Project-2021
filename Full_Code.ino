const int sensor = 5;     // the number of the pushbutton pin
const int buzzer = 4;      // the number of the LED pin
const int button = 3;

 

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

 

void setup() {
  // initialize the LED pin as an output:
  pinMode(buzzer, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(sensor, INPUT);

}

 

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(sensor);
  int buttonPressed = digitalRead(button);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
   
    do{digitalWrite(buzzer, HIGH);
    buttonPressed = digitalRead(button);
    } while (buttonPressed == LOW);
    delay(100);

   
    }
   
   else {
    // turn LED off:
    digitalWrite(buzzer, LOW);
  }
}
