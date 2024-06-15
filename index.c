#include "Servo.h"

Servo servo;
int prox = 0;

void setup() {
    Serial.begin(9600);
    servo.attach(9);
    Serial.begin(9600);
    pinMode(prox, INPUT);
}

void loop() {
    servo.write(90);
    delay(500);
    servo.write(0);
    delay(500);

    if (Serial.available() > 0) {
        int angle = Serial.parseInt();
        servo.write(angle);
    }

    Serial.println(servo.read());


    if(!digitalReead(prox)){
        Serial.println("Proximidade detectada");
    }
}


The code is very simple. It reads the angle from the serial port and writes it to the servo. 
The code is uploaded to the Arduino board. 
Step 3: Control the Servo Motor with Python 
Now, we will write a Python script to control the servo motor. 
First, we need to install the  pyserial  library. 
pip install pyserial

Now, write the following Python script.
