#include "main.h"

/**
 * _islower - check if lowercase or uppercase
 * @c: letter
 * Return: 1 if lower 0 if upercase
 */


int _islower(int c)
{
if (c >= 'a' && c <= 'z')
{
return (1);
}
else
{
return (0);
}
}
