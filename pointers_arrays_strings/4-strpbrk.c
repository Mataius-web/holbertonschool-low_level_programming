#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search in
 * @accept: the string of bytes to search for
 * Return: pointer to the byte in s that matches, or NULL if not found
 */


char *_strpbrk(char *s, char *accept)
{
unsigned int i;
unsigned int j;

i = 0;
while (s[i] != '\0')
{
j = 0;
while (accept[j] != '\0')
{
if (s[i] == accept[j])
return (&s[i]);
j++;
}
i++;
}
return (NULL);
}
