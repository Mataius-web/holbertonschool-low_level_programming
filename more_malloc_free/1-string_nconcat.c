#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2
 * Return: pointer to newly allocated memory containing s1
 * followed by the first n bytes of s2, or NULL if it fails
 */


char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *new;
unsigned int len1 = 0, len2 = 0, i, j;

if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";

while (s1[len1])
len1++;

while (s2[len2])
len2++;

if (n >= len2)
n = len2;

new = malloc(len1 + n + 1);
if (new == NULL)
return (NULL);

for (i = 0; i < len1; i++)
new[i] = s1[i];

for (j = 0; j < n; j++)
new[i + j] = s2[j];

new[len1 + n] = '\0';

return (new);
}
