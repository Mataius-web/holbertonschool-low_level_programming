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
if (alphabet == 'e' || alphabet == 'q')
{
++alphabet;
}
else
{
putchar(alphabet);
++alphabet;
}
}
putchar('\n');
return (0);
}
