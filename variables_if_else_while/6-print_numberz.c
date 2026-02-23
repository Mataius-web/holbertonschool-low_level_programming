#include <stdio.h>

/**
 * main - print numbers from 0 to 9 with putchar
 * Return: 0 if the program run
 */

int main(void)
{
unsigned int numbers;
for (numbers = 0; numbers <= 9; numbers++)
{
putchar(numbers + '0');
}
putchar('\n');
return (0);
}
