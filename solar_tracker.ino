#define BUTTON_PIN 5
#define BUTTON_PIN1 6
#define BUTTON_PIN2 7
#define BUTTON_PIN3 8
#define BUTTON_PIN4 9
#define stepPin1 10
#define stepPin2 12
char Incoming_value = 0;
int sensorValue = 0;
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int tol = 0;
int tol1 = 0;
int tol2 = 0;
int tol3 = 0 ;
int tol4 = 0 ;
int tol5 = 0 ;
void setup()
{
  Serial.begin(9600);
  sensorValue = analogRead(A0);
  sensorValue1 = analogRead(A1);
  sensorValue2 = analogRead(A2);
  sensorValue3 = analogRead(A3);
  tol = (sensorValue1 + sensorValue)/2 ;
  tol1 = (sensorValue2 + sensorValue3)/2 ;
  tol2 = tol - tol1 ;
  tol3 = (sensorValue + sensorValue3)/2 ;
  tol4 = (sensorValue1 + sensorValue2)/2 ;
  tol5 = tol3 - tol4 ;

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  pinMode (11, OUTPUT);
  pinMode (stepPin1, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (stepPin2, OUTPUT);
}
void loop()
{

    if (digitalRead(BUTTON_PIN) == 1)
    {

      if (digitalRead(BUTTON_PIN1)== 0) {
        for (int i = 0; i <= 25; i++) {
          digitalWrite(11, HIGH);
          digitalWrite(stepPin1, HIGH);
          delayMicroseconds(20);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(20);
          delay(10);
        }
      }
      if (digitalRead(BUTTON_PIN2)== 0) {
        for (int i = 0; i <= 25; i++) {
          digitalWrite(11, LOW);
          digitalWrite(stepPin1, HIGH);
          delayMicroseconds(20);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(20);
          delay(10);
        }
      }
      if (digitalRead(BUTTON_PIN3)== 0) {
        for (int i = 0; i <= 25; i++) {
          digitalWrite(13, HIGH);
          digitalWrite(stepPin2, HIGH);
          delayMicroseconds(20);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(20);
          delay(10);
        }
      }
      if (digitalRead(BUTTON_PIN4)== 0) {
        for (int i = 0; i <= 25; i++) {
          digitalWrite(13, LOW);
          digitalWrite(stepPin2, HIGH);
          delayMicroseconds(20);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(20);
          delay(10);
        }
      }
      if (Serial.available()  > 0){
        Incoming_value = Serial.read();

        if (Incoming_value == '1') {
          for (int i = 0; i <= 25; i++) {
            digitalWrite(11, HIGH);
            digitalWrite(stepPin1, HIGH);
            delayMicroseconds(20);
            digitalWrite(stepPin1, LOW);
            delayMicroseconds(20);
            delay(10);
          }
        }
        if(Incoming_value == '2') {
           for (int i = 0; i <= 25; i++) {
            digitalWrite(11, LOW);
            digitalWrite(stepPin1, HIGH);
            delayMicroseconds(20);
            digitalWrite(stepPin1, LOW);
            delayMicroseconds(20);
            delay(10);
          }
        }
        if(Incoming_value == '3') {
          for (int i = 0; i <= 25; i++) {
           digitalWrite(13, HIGH);
           digitalWrite(stepPin2, HIGH);
           delayMicroseconds(20);
           digitalWrite(stepPin2, LOW);
           delayMicroseconds(20);
           delay(10);
          }
        }
        if(Incoming_value == '4') {
          for (int i = 0; i <= 25; i++) {
           digitalWrite(13, LOW);
           digitalWrite(stepPin2, HIGH);
           delayMicroseconds(20);
           digitalWrite(stepPin2, LOW);
           delayMicroseconds(20);
           delay(10);
          }
        }
      }
    }
    if (digitalRead(BUTTON_PIN) == 0)
    {
          sensorValue = analogRead(A0);
          sensorValue1 = analogRead(A1);
          sensorValue2 = analogRead(A2);
          sensorValue3 = analogRead(A3);
          tol = (sensorValue1 + sensorValue)/2 ;
          tol1 = (sensorValue2 + sensorValue3)/2 ;
          tol2 = tol - tol1 ;
          tol3 = (sensorValue + sensorValue3)/2 ;
          tol4 = (sensorValue1 + sensorValue2)/2 ;
          tol5 = tol3 - tol4 ;

          Serial.println(sensorValue);
         Serial.println(sensorValue1);
         Serial.println(sensorValue2);
          Serial.println(sensorValue3);
          Serial.println(tol2);
          Serial.println(tol5);

         delay(500);

      if (  tol2 > 30 ) {
        for (int i = 0; i <= 25; i++) {
          digitalWrite(11, HIGH);
          digitalWrite(stepPin1, HIGH);
          delayMicroseconds(20);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(20);
          delay(10);
        }
      }
      if ( tol2 < -30 ) {
        for (int i = 0; i <= 25; i++) {
          digitalWrite(11, LOW);
          digitalWrite(stepPin1, HIGH);
          delayMicroseconds(20);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(20);
          delay(10);
        }
      }
      if ( tol5 > 30 ) {
        for (int i = 0; i <= 25; i++) {
          digitalWrite(13, HIGH);
          digitalWrite(stepPin2, HIGH);
          delayMicroseconds(20);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(20);
          delay(10);
        }
      }
      if ( tol5 < -30 ) {
        for (int i = 0; i <= 25; i++) {
          digitalWrite(13, LOW);
          digitalWrite(stepPin2, HIGH);
          delayMicroseconds(20);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(20);
          delay(10);
        }
      }

    }
}
