/* Inital Declaration of user-defined functions */
void buttonInteract(int buttonPin, int ledPin, int& buttonState, bool& isOnState, int& lastButtonState);
void turnOnLED(int ledPin, bool& isOnState);
void turnOffLED(int ledPin, bool& isOnState);

/* Define the constants */
const int buttonPin1 = 4; // Using GPIO 4
const int buttonPin2 = 18; // Using GPIO 19
const int ledPin1 = 5; // Using GPIO 5
const int ledPin2 = 19; // Using GPIO 18
const int buttonDelay = 50; // Button delay predefined (to avoid button bounce)
const int baudRate = 115200; // Baud Rate

/* Define Global Variable */
int buttonState1 =  0; // Initial state of button is 0 (low) which is off
bool isOnState1 = false; // Initial state if lights will be on or off 
int lastButtonState1 = LOW; // Initial last state of button

int buttonState2 =  0; // Initial state of button is 0 (low) which is off
bool isOnState2 = false; // Initial state if lights will be on or off 
int lastButtonState2 = LOW; // Initial last state of button

/* The setup function runs once when you press reset or power the board */
void setup() {
  Serial.begin(baudRate); // Defining the data transfer rate (Baud Rate)
  pinMode(buttonPin1, INPUT); // Defining the GPIO for the button and declaring it as an input
  pinMode(ledPin1, OUTPUT); // Defining the GPIO for the LED and declaring it as an output
  pinMode(buttonPin2, INPUT); // Defining the GPIO for the button and declaring it as an input
  pinMode(ledPin2, OUTPUT); // Defining the GPIO for the LED and declaring it as an output
}

/* The loop function runs over and over again forever */
void loop() {
  // Button 1
  buttonInteract(buttonPin1, ledPin1, buttonState1, isOnState1, lastButtonState1);

  // Button 2
  buttonInteract(buttonPin2, ledPin2, buttonState2, isOnState2, lastButtonState2);
}


/* User defined function to turn on LED */
void turnOnLED(int ledPin, bool& isOnState) {
  digitalWrite(ledPin, HIGH);
  isOnState = true;
  Serial.println("LED is ON for: "); Serial.println(ledPin);
}

/* User defined function to turn off LED */
void turnOffLED(int ledPin, bool& isOnState) {
  digitalWrite(ledPin, LOW);
  isOnState = false;
  Serial.println("LED is OFF for: "); Serial.println(ledPin);
}

void buttonInteract(int buttonPin, int ledPin, int& buttonState, bool& isOnState, int& lastButtonState) {
  buttonState = digitalRead(buttonPin); 

  // Will enter the IF statement if button is pressed and LED is OFF
  if (buttonState == HIGH && lastButtonState == LOW) {
      if (isOnState) {
        turnOffLED(ledPin, isOnState);
      } else {
        turnOnLED(ledPin, isOnState);
      } 
    delay(buttonDelay); // This is to avoid button bounce (debounce logic)
  }
  lastButtonState = buttonState; // This will store the previous button state before it starts a new loop
}