/**
 * Binky test
 */

#include <core_pins.h>

int main()
{
    char i = 0;
    pinMode(13, OUTPUT);

    while(1)
    {
        delay(250);
        i ^= 1;
        digitalWrite(13, i);    
    }

    return 0;
}
