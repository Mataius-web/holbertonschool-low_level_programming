#include "main.h"

/**
 * print_line - print a line with _
 * @n: number of repetition _
 */

void print_line(int n)
{
int i;
if (n > 0)
{
for (i = 0; i < n; i++)
{
_putchar('_');
}
}
_putchar('\n');
}
