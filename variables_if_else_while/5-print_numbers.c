#include <stdio.h>

/**
 * main - print numbers from 0 to 9
 * Return: 0 if the program run
 */

int main(void)
{
unsigned int numbers = 0;
while (numbers <= 9)
{
printf("%d", numbers);
++numbers;
}
putchar('\n');
return (0);
}
