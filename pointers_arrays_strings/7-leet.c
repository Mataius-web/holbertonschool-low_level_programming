#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: the string to encode
 * Return: pointer to the modified string
 */


char *leet(char *s)
{
int i;
int j;
char src[] = "aAeEoOtTlL";
char dst[] = "4433007711";

i = 0;
while (s[i] != '\0')
{
j = 0;
while (src[j] != '\0')
{
if (s[i] == src[j])
s[i] = dst[j];
j++;
}
i++;
}
return (s);
}
