#include <Arduino.h>

void yellow_led_left_on()
{
    digitalWrite(A4, HIGH);
}

void yellow_led_left_off()
{
    digitalWrite(A4, LOW);
}

void yellow_led_right_on()
{
    digitalWrite(A3, HIGH);
}

void yellow_led_right_off()
{
    digitalWrite(A3, LOW);
}