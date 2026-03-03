#include <stdio.h>
#include "main.h"

/**
 * print_array - print n elements of an array of integer
 * @a: the array to print
 * @n: number of elements to print
 */


void print_array(int *a, int n)
{
int i;

i = 0;
while (i < n)
{
printf("%d", a[i]);
if (i < n - 1)
{
printf(", ");
}
i++;
}
printf("\n");
}
