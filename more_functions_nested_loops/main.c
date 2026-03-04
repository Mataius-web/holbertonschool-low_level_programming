#include "main.h"

/**
 * print_triangle - prints a triangle using #
 * @size: size of the triangle
 */

void print_triangle(int size)
{
int i, spaces, hashes;

if (size <= 0)
{
_putchar('\n');
return;
}

for (i = 1; i <= size; i++)
{
for (spaces = 0; spaces < size - i; spaces++)
{
_putchar(' ');
}
for (hashes = 0; hashes < i; hashes++)
{
_putchar('#');
}
_putchar('\n');
}
}
