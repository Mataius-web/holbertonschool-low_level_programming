#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer to newly allocated memory containing s1 followed by s2,
 * or NULL if it fails
 */


char *str_concat(char *s1, char *s2)
{
char *str;
int i, j, len1, len2;

if (s1 == NULL)
s1 = "";

if (s2 == NULL)
s2 = "";

len1 = 0;
while (s1[len1])
len1++;

len2 = 0;
while (s2[len2])
len2++;

str = malloc(sizeof(char) * (len1 + len2 + 1));
if (str == NULL)
return (NULL);

i = 0;
while (i < len1)
{
str[i] = s1[i];
i++;
}

j = 0;
while (j < len2)
{
str[i] = s2[j];
i++;
j++;
}

str[i] = '\0';

return (str);
}
