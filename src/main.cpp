/*
  Project to build a robot named Yuppie on base Arduino UNO R3.
  version: 0.0.3
  date: 28.08.2024
  modified 31.08.2024
  Developer: Valeriy Chernobrovyi (chernobrovyivs)
*/
// Подключаем библиотеку управления сервомоторами
#include <Servo.h>
#include <Sonar.h>

Servo neck;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, I'm robot named Yuppie ;)");
  neck.attach(A5);

  // Инициализируем дальномер Trig = A0, Echo = A1
  Sonar_init(A0, A1);
}

int sonar_func() {
  int prepyatstvie = Sonar(500);
  Serial.print("Distance = ");
  Serial.print(prepyatstvie);
  Serial.println(" cm.");

  return prepyatstvie;
}

void loop() {
  int i;

  for(i=10; i<=180; i=i+10)
  {
    neck.write(i);
    sonar_func();
    delay(1000);
  }

  for(i=180; i>=0; i=i-10)
  {
    neck.write(i);
    sonar_func();
    delay(1000);
  }
}