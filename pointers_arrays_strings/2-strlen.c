#include "main.h"

/**
 * _strlen - return the length of a string
 * @s: checked string
 * Return: result
 */


int _strlen(char *s)
{
int result;

result = 0;
while (s[result] != '\0')
result++;
return (result);
}
