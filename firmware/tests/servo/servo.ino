#include <Servo.h>

#define pin_servo 3
Servo servo;

void setup()
{
    servo.attach(pin_servo);
    servo.write(0);
}

void loop()
{
    int x;

    for (x = 0; x < 180; x++)
    {
        servo.write(x);
        delay(15);
    }

    for (x = 180; x > 0; x--)
    {
        servo.write(x);
        delay(15);
    }
}