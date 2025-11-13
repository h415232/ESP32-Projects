/* Inital Declaration of user-defined functions */
void turnOnLED(int ledPin);
void turnOffLED(int ledPin);

/* Define the constants */
const int buttonPin = 4; // Using GPIO 4
const int ledPin1 = 5; // Using GPIO 5
const int ledPin2 = 18; // Using GPIO 18
const int buttonDelay = 50; // Button delay predefined (to avoid button bounce)
const int baudRate = 115200 // Baud Rate


/* Define Global Variable */
int buttonState =  0; // Initial state of button is 0 (low) which is off
bool isOnState = false; // Initial state if lights will be on or off 
int lastButtonState = LOW; // Initial last state of button

/* The setup function runs once when you press reset or power the board */
void setup() {
  Serial.begin(baudRate); // Defining the data transfer rate (Baud Rate)
  pinMode(buttonPin, INPUT); // Defining the GPIO for the button and declaring it as an input
  pinMode(ledPin, OUTPUT); // Defining the GPIO for the LED and declaring it as an output
}

/* The loop function runs over and over again forever */
void loop() {
  // Will read the current state of the button
  buttonState = digitalRead(buttonPin); 

  // Will enter the IF statement if button is pressed and LED is OFF
  if (buttonState == HIGH && lastButtonState == LOW) {
      if (isOnState) {
        turnOffLED();
      } else {
        turnOnLED();
      } 
    delay(buttonDelay); // This is to avoid button bounce
  }
  lastButtonState = buttonState; // This will store the previous button state before it starts a new loop
}


/* User defined function to turn on LED */
void turnOnLED(int ledPin) {
  digitalWrite(ledPin, HIGH);
  isOnState = true;
  Serial.println("LED is ON");
}

/* User defined function to turn off LED */
void turnOffLED(int ledPin) {
  digitalWrite(ledPin, LOW);
  isOnState = false;
  Serial.println("LED is OFF");
}
