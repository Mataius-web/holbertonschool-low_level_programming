#include "main.h"

/**
 * print_rev - print a string in reverse
 * @s: string printed
 */

void print_rev(char *s)
{
int length;

length = 0;
while (s[length] != '\0')
length++;
while (length > 0)
{
length--;
_putchar(s[length]);
}
_putchar('\n');
}
