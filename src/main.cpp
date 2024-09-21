/*
  Project to build a robot named Yuppie on base Arduino UNO R3.
  version: 0.1.1
  date: 28.08.2024
  modified 08.09.2024
  Developer: Valeriy Chernobrovyi (chernobrovyivs)
*/

// Подключаем библиотеку управления через Bluetooth
#include <BluetoothRC.h>

// Подключаем библиотеку навигации робота по Сонару
#include <robot_obstacle_avoidance.h>



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, I'm robot named Yuppie ;)");

  neck.attach(A5);

  //  Инициализируем ультразвуковой сонар (дальномер) Trig = A0, Echo = A1
  setup_sonar_system(A0, A1);

  // Инициализирует драйвер двигателя Motor L1 = 4, Motor L2 = 5, Motor R1 = 6, Motor R2 = 7
  setup_motor_system(4, 5, 6, 7);

  _stop();

  // Инициализирует bluetooth модуль
  Bluetooth_init_method();

  pinMode(13, INPUT);
  
  // Устанавливаем скорость передачи данных по кабелю.
  // Порт компьютера
  Serial.begin(9600);
}

void loop() {
  bool mode = (bool)digitalRead(13);

  if (mode == 1)
  {
    bluetooth_remote_control();
    Serial.println("On mode Bluetooth Remote Control");
  } else
  {
    search_free_on_space_revolution();
    Serial.println("On mode Autonomics navigation");
  }
}