/*
  Project to build a robot named Yuppie on base Arduino UNO R3.
  version: 0.1.0
  date: 28.08.2024
  modified 08.09.2024
  Developer: Valeriy Chernobrovyi (chernobrovyivs)
*/

// Подключаем библиотеку управления через Bluetooth
#include <BluetoothRC.h>
// Подключаем библиотеку управления сервомоторами
#include <Servo.h>
// Подключаем библиотеку управления ультразвуковым датчиком
#include <Sonar.h>

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

  // Устанавливаем скорость передачи данных для НС-05 (Bluetooth-модуль).
  BTSerial.begin(9600);
  // Переключаем A0 в двоичный режим работы, на передачу.
  // если вы его еще не отключили
  pinMode(14, OUTPUT);
  // Устанавливаем скорость передачи данных по кабелю.
  // Порт компьютера
  //Serial.begin(9600);
  _time = micros();
}

int sonar_func() {
  int prepyatstvie = Sonar(1000);
  Serial.print("Distance = ");
  Serial.print(prepyatstvie);
  Serial.println(" cm.");

  return prepyatstvie;
}

void loop() {
  bluetooth_remote_control();
}