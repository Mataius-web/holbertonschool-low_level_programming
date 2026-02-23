#include <stdio.h>

/**
 * main - print numbers from 0 to 9 with comma and space
 * 0->8 and $ for 9
 * Return: 0 if the program run
 */

int main(void)
{
int i;

i = 0;
while (i <= 9)
{
putchar('0' + i);
if (i < 9)
{
putchar(',');
putchar(' ');
}
i++;
}
putchar('\n');
return (0);
}
