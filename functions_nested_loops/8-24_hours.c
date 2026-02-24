#include "main.h"

/**
 * jack_bauer - print every minutes of a day
 */

void jack_bauer(void)
{
int minute;
int hours;

for (hours = 0; hours <= 23; hours++)
{

for (minute = 0; minute <= 59; minute++)
{
_putchar(hours / 10 + '0');
_putchar(hours % 10 + '0');
_putchar(':');
_putchar(minute / 10 + '0');
_putchar(minute % 10 + '0');
_putchar('\n');
}
}
}
