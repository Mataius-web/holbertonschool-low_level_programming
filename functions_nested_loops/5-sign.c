#include "main.h"

/**
 * print_sign - print the sign of n
 * @n: number
 * Return: 1 if + and n greater than 0
 * 0 is n is 0 -1 if - and n less than 0
 */

int print_sign(int n)
{

if (n > 0)
{
_putchar('+');
return (1);
}
else if (n == 0)
{
    _putchar('0');
    return (0);
}
else
{
_putchar('-');
return (-1);
}
}
