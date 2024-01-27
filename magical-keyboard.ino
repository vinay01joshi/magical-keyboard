#include <Keyboard.h>

const int buttonPin = 9; // Change this to the actual pin you connected the button to
const int buttonPin2 = 8;
int buttonState = HIGH;  // HIGH when the button is not pressed
int buttonState2 = HIGH; 
int lastButtonState = HIGH;
int lastButton2State = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2,INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState == LOW && lastButtonState == HIGH) {
    // Button pressed, send key press
    Keyboard.press(KEY_UP_ARROW);  // Change to KEY_DOWN_ARROW for down
    delay(50);  // Adjust delay as needed
  } else if (buttonState == HIGH && lastButtonState == LOW) {
    // Button released, send key release
    Keyboard.release(KEY_UP_ARROW);  // Change to KEY_DOWN_ARROW for down
    delay(50);  // Adjust delay as needed
  }

  if (buttonState2 == LOW && lastButton2State == HIGH) {
    // Button pressed, send key press
    Keyboard.press(KEY_DOWN_ARROW);  // Change to KEY_DOWN_ARROW for down
    delay(50);  // Adjust delay as needed
  } else if (buttonState2 == HIGH && lastButton2State == LOW) {
    // Button released, send key release
    Keyboard.release(KEY_DOWN_ARROW);  // Change to KEY_DOWN_ARROW for down
    delay(50);  // Adjust delay as needed
  }

  lastButtonState = buttonState;
  lastButton2State = buttonState2;
}
