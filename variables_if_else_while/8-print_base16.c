#include <stdio.h>

/**
 * main - print numbers base16 in lowercase
 * with putchar
 * Return: 0 if the program run
 */

int main(void)
{
unsigned int numbers;

for (numbers = 0; numbers < 16; numbers++)

if (numbers < 10)
{
putchar('0' + numbers);
}
else
{
putchar('a' + (numbers - 10));
}

putchar('\n');

return (0);
}
