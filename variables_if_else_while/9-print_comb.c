#include <stdio.h>

/**
 * main - print numbers from 0 to 9 with comma and space
 * 0->8 and $ for 9
 * Return: 0 if the program run
 */

int main(void)
{
unsigned int numbers;
for (numbers = 0; numbers <= 9; numbers++)
{
putchar(numbers + '0');
if (numbers != 9)
{
putchar(',');
putchar(' ');
}
else
{
putchar('\0');
}
}
return (0);
}
