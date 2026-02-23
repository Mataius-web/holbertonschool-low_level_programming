#include <stdio.h>

/**
 * main - print alphabet in lowercase
 * Return: 0 if the program run
 */

int main(void)
{
char alphabet = 'a';
while (alphabet <= 'z')
{
putchar(alphabet);
putchar('\n');
++alphabet;
}
return (0);
}
