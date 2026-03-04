#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: the string to modify
 * Return: pointer to the modified string
 */


char *cap_string(char *s)
{
int i;
int cap;

i = 0;
cap = 1;

while (s[i] != '\0')
{
if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
s[i] == ',' || s[i] == ';' || s[i] == '.' ||
s[i] == '!' || s[i] == '?' || s[i] == '"' ||
s[i] == '(' || s[i] == ')' || s[i] == '{' ||
s[i] == '}')
cap = 1;
else if (cap == 1 && s[i] >= 'a' && s[i] <= 'z')
{
s[i] = s[i] - 32;
cap = 0;
}
else
cap = 0;
i++;
}
return (s);
}
