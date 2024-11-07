#include <BleCombo.h>

const int buttonPin = 0;  // the number of the pushbutton pin
int buttonState = 0;
int curState = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting work!");
  Keyboard.begin();
  Mouse.begin();
  pinMode(buttonPin, INPUT);
}

void loop() {
  curState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (curState == LOW && buttonState!=LOW) {
    if (Keyboard.isConnected()) {
      Keyboard.write(KEY_MEDIA_VOLUME_DOWN);
    }
    Serial.println("Button pressed");
  } 
  buttonState = curState;

  // Check if there is data available on the serial port
  if (Serial.available() > 0) {
    // Read the input from serial
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove any leading/trailing whitespace

    // Perform actions based on the input command
    if (input.equalsIgnoreCase("click")) {
      Serial.println("Received 'click' command. Sending left mouse click...");
      if (Keyboard.isConnected()) {
        Mouse.click(MOUSE_LEFT);
      }
    } 
    else if (input.equalsIgnoreCase("down")) {
      Serial.println("Received 'down' command. Sending down...");
      if (Keyboard.isConnected()) {
        Keyboard.write(KEY_MEDIA_VOLUME_DOWN);
      }
    } 
    else if (input.equalsIgnoreCase("up")) {
      Serial.println("Received 'up' command. Sending up key...");
      if (Keyboard.isConnected()) {
        Keyboard.write(KEY_MEDIA_VOLUME_DOWN);
      }
    } 
    else if (input.equalsIgnoreCase("toggle")) {
      Serial.println("Received 'toggle' command. Sending Toggle key...");
      if (Keyboard.isConnected()) {
        Keyboard.write(KEY_MEDIA_PLAY_PAUSE);
      }
    } 
    else if (input.equalsIgnoreCase("tab")) {
      Serial.println("Received 'tab' command. Sending Tab key...");
      if (Keyboard.isConnected()) {
        Keyboard.write(KEY_TAB);
      }
    } 
    else if (input.equalsIgnoreCase("enter")) {
      Serial.println("Received 'enter' command. Sending Enter key...");
      if (Keyboard.isConnected()) {
        Keyboard.write(KEY_RETURN);
      }
    }
    // New mouse movement commands
    else if (input.equalsIgnoreCase("up")) {
      Serial.println("Received 'up' command. Moving mouse up...");
      if (Keyboard.isConnected()) {
        Mouse.move(0, -20);  // Move up by 20 pixels
      }
    } 
    else if (input.equalsIgnoreCase("down")) {
      Serial.println("Received 'down' command. Moving mouse down...");
      if (Keyboard.isConnected()) {
        Mouse.move(0, 20);  // Move down by 20 pixels
      }
    } 
    else if (input.equalsIgnoreCase("left")) {
      Serial.println("Received 'left' command. Moving mouse left...");
      if (Keyboard.isConnected()) {
        Mouse.move(-20, 0);  // Move left by 20 pixels
      }
    } 
    else if (input.equalsIgnoreCase("right")) {
      Serial.println("Received 'right' command. Moving mouse right...");
      if (Keyboard.isConnected()) {
        Mouse.move(20, 0);  // Move right by 20 pixels
      }
    }
  }
}
