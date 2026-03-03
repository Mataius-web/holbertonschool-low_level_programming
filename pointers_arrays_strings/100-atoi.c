#include "main.h"

/**
 * _atoi - convert a string to a integer
 * @s: the string to convert
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
int i;
int sign;
int result;
int found;

i = 0;
sign = 1;
result = 0;
found = 0;

while (s[i] != '\0')
{
if (found == 0 && s[i] == '-')
sign = sign * -1;
else if (found == 0 && s[i] == '+')
sign = sign * 1;
else if (s[i] >= '0' && s[i] <= '9')
{
found = 1;
result = result * 10 + (s[i] - '0');
}
else if (found == 1)
break;
i++;
}
return (sign * result);
}
