#include <stdio.h>

/**
 * main - print reverse alphabet in lowercase
 * Return: 0 if the program run
 */

int main(void)
{
char alphabet = 'z';
while (alphabet >= 'a')
{
putchar(alphabet);
--alphabet;
}
putchar('\n');
return (0);
}
