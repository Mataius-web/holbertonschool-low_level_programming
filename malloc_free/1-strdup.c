#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * containing a copy of the string given as a parameter
 * @str: string to duplicate
 * Return: pointer to duplicated string, or NULL if it fails
 */

char *_strdup(char *str)
{
char *dup;
int i, len;

if (str == NULL)
return (NULL);

len = 0;
while (str[len])
len++;

dup = malloc(sizeof(char) * (len + 1));
if (dup == NULL)
return (NULL);

i = 0;
while (i <= len)
{
dup[i] = str[i];
i++;
}

return (dup);
}
