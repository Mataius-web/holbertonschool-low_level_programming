#include "main.h"

/**
 * print_last_digit - print the last digit
 * @n: number
 * Return: last digit value
 */

int print_last_digit(int n)
{
int last_digit = n % 10;
if ((n > 0) || (n == 0))
{
return (last_digit);
}
else
{
return (-last_digit);
}
}
