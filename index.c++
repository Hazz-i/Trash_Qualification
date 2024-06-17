#include <Servo.h>

#define echoPin 3
#define triggerPin 4
#define proxInd 7

Servo myServo;

void setup() {
    Serial.begin(9600);
    myServo.attach(9); 
    pinMode(proxInd, INPUT);
    myServo.write(100);
}

void loop() {   
  int cm = 0;
  int readInd = digitalRead(proxInd);
  cm = (0.03446 * bacaJarak(echoPin, triggerPin)) / 2;

  int data = 0; // Variabel untuk nilai persentase

    if (cm >= 0 && cm <= 15) {
      // Konversi dari cm ke persen antara 0 cm hingga 16 cm
      data = map(cm, 0, 15, 100, 0);

      // Serial.println("jarak = " + String(data) + "%");
      // delay(1000);
    } 


  if(readInd == 1){
    Serial.println("HIGH: " + readInd);  
    for (int angle = 100; angle <= 180; angle += 1) {
      myServo.write(angle);
      delay(5);

      if(angle == 180){
        delay(1000);
        myServo.write(100);
      }
    }

  }
  
  if(readInd == 0){
    Serial.println("LOW: " + readInd);
    delay(1000);

    if (data != 0) {
        for (int angle = 100; angle >= 0; angle -= 1) {
          myServo.write(angle);
          delay(5);

          if(angle == 0){
            delay(1000);
            myServo.write(100);
          }
        }
      }
      // Serial.println("ADA BARANG");
      // Serial.println(data);
      // delay(1000);


    if (data == 0){
      Serial.println("TIDAK ADA BARANG");
      Serial.println(data);
      delay(1000);
    }
  }
}

long bacaJarak(int tri, int echo) {
  pinMode(triggerPin, OUTPUT);             
  digitalWrite(triggerPin, LOW);          
  digitalWrite(triggerPin, HIGH);         
  delayMicroseconds(10);                   
  digitalWrite(triggerPin, LOW);  
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);          
}