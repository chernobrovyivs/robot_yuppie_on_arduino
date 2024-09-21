#include <SoftwareSerial.h>
#include <Arduino.h>
#include <move_case.h>
#include <MotorDriverX2Lib.h>

//Создаем последовательный порт на пинах 13-чтение и 2-передача.
SoftwareSerial BTSerial(2, 3); // RX, TX
// Хранит время последнего нажатия кнопки.
unsigned long _time;
// Переменная для приема данных по Bluetooth.
char bt_input;

void Bluetooth_init_method()
{
    // Устанавливаем скорость передачи данных для НС-05 (Bluetooth-модуль).
    BTSerial.begin(9600);
    // Переключаем A0 в двоичный режим работы, на передачу.
    // если вы его еще не отключили
    pinMode(14, OUTPUT);

    _time = micros();
}

void bluetooth_remote_control()
{
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
        Serial.println(bt_input);
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