#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements
 * @size: size of each element
 * Return: pointer to the allocated memory, or NULL if it fails
 */


void *_calloc(unsigned int nmemb, unsigned int size)
{
void *ptr;
unsigned int i;
char *p;
unsigned int total;

if (nmemb == 0 || size == 0)
return (NULL);

total = nmemb * size;

ptr = malloc(total);
if (ptr == NULL)
return (NULL);

p = ptr;

for (i = 0; i < total; i++)
p[i] = 0;

return (ptr);
}
