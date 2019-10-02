int havaKalitesi;
float temp = 0;
int tempPin = 0;
//char val;
int state;

const int motorA1  = 2;  // L298N'in IN3 Girişi
const int motorA2  = 3;  // L298N'in IN1 Girişi
const int motorB1  = 4; // L298N'in IN2 Girişi
const int motorB2  = 5;  // L298N'in IN4 Girişi

void setup()
{
  Serial.begin(9600);
  //establishContact();
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    if (state == 'z') {
      temp = analogRead(tempPin);
      temp = temp * 0.48828125;
      havaKalitesi = analogRead(1); // mq135
      Serial.println("Havadaki Karbon Oranı: ");
      Serial.println(havaKalitesi, DEC);
      Serial.print(",");
      Serial.print("Sicaklik (Celcius): ");
      Serial.println(temp);
      Serial.print(",");
    }
    delay(10);
  }
  else {
    Serial.print('A');
    Serial.println(analogRead(A0));
    Serial.print('B');
    Serial.println(analogRead(A1));
    delay(50);
  }

  if (state == 'F') {
    ileri();
    delay(500);
  }
  else if (state == 'B') {
    geri();
    delay(500);
  }
  else if (state == 'L') {
    sol();
    delay(500);
  }
  else if (state == 'R') {
    sag();
    delay(500);
  }
  else {
    dur();
    delay(500);
  }
}


int sag() {
  digitalWrite(motorA1, 0);
  digitalWrite(motorA2, 1);
  digitalWrite(motorB1, 0);
  digitalWrite(motorB2, 1);
}
/*int ilerisag() {
  analogWrite(9,125);
  digitalWrite(motorA1, 0);
  digitalWrite(motorA2, 1);
  digitalWrite(motorB1, 0);
  digitalWrite(motorB2, 1);
}
int sol() {
  digitalWrite(motorA1, 0);
  digitalWrite(motorA2, 1);
  digitalWrite(motorB1, 1);
  digitalWrite(motorB2, 0);
}

int ileri() {
  digitalWrite(motorA1, 1);
  digitalWrite(motorA2, 0);
  digitalWrite(motorB1, 1);
  digitalWrite(motorB2, 0);
}*/

int geri() {
  digitalWrite(motorA1, 0);
  digitalWrite(motorA2, 1);
  digitalWrite(motorB1, 0);
  digitalWrite(motorB2, 1);
}

int dur() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}

