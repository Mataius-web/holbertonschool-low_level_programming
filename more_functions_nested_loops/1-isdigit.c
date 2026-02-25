#include "main.h"

/**
 * _isdigit - check if c is a number from 0 to 9
 * @c: number
 * Return: 1 if it's a digit and 0 if not
 */

int _isdigit(int c)
{
if (c >= '0' && c <= '9')
{
return (1);
}
else
{
return (0);
}
}
