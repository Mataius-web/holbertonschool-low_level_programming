#include "main.h"

/**
 * _isalpha - check if char is uppercase or lowercase
 * @c: letter
 * Return: 1 if true 0 if false
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
{
return (1);
}
else
{
return (0);
}
}
