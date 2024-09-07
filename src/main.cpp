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
// Подключаем библиотеку для создания дополнительных последовательных (Serial) портов.
#include <SoftwareSerial.h>
#include <move_case.h>

//Создаем последовательный порт на пинах 13-чтение и 2-передача.
SoftwareSerial BTSerial(10, 11); // RX, TX
// Переменная для приема данных по Bluetooth.
char bt_input;
// Хранит время последнего нажатия кнопки.
unsigned long _time;

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
  if (BTSerial.available())
  {
    // Читаем команду и заносим ее в переменную. char преобразует
    // код символа команды в символ.
    bt_input = (char)BTSerial.read();
    // Отправляем команду в порт, чтобы можно было
    // их проверить в "Мониторе порта".
    //Serial.println(bt_input);
    //Вызов функции выбора действия по команде
    move_case(bt_input);
    _time = micros();
  }
  if ((micros() - _time) > _move_time)
  {
    _stop();
  }
  if ((micros() - _time) >= 500)
  {
    _time = micros();
    move_case(bt_input);
  }
}