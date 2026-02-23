#include <stdio.h>

/**
 * main - print alphabet in lowercase and uppercase
 * Return: 0 if the program run
 */

int main(void)
{
char alphabet = 'a';
char alphabetCaps = 'A';
while (alphabet <= 'z')
{
putchar(alphabet);
++alphabet;
}
while (alphabetCaps <= 'Z')
{
putchar(alphabetCaps);
++alphabetCaps;
}
putchar('\n');
return (0);
}
