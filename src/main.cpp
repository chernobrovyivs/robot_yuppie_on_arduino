/*
  Project to build a robot named Yuppie on base Arduino UNO R3.
  version: 0.0.4
  date: 28.08.2024
  modified 01.09.2024
  Developer: Valeriy Chernobrovyi (chernobrovyivs)
*/

// Подключаем библиотеку управления сервомоторами
#include <Servo.h>
// Подключаем библиотеку управления ультразвуковым датчиком
#include <Sonar.h>
// Подключаем библиотеку управления двигателями (4 двигателя)
#include <Motor.h>

Servo neck;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, I'm robot named Yuppie ;)");
  neck.attach(A5);

  // Инициализируем дальномер Trig = A0, Echo = A1
  Sonar_init(A0, A1);
  setup_motor_system(4, 5, 6, 7);

  _stop();
}

int sonar_func() {
  int prepyatstvie = Sonar(1000);
  Serial.print("Distance = ");
  Serial.print(prepyatstvie);
  Serial.println(" cm.");

  return prepyatstvie;
}

void loop() {
  int i;
/*
  for(i=10; i<=180; i=i+10)
  {
    neck.write(i);
    sonar_func();
    delay(2000);
  }

  for(i=180; i>=0; i=i-10)
  {
    neck.write(i);
    sonar_func();
    delay(2000);
  }
*/

  forward();
  delay(5000);
  forward_left();
  delay(1000);
  forward();
  delay(1000);
  forward_right();
  delay(1000);
  _stop();
  delay(1000);
  backward();
  delay(800);
}