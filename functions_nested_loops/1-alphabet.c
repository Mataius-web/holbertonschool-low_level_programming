#include "main.h"

/**
 * main - print the alphabet
 * Return: 0 if run
 */

void print_alphabet(void)
{
char alphabet = 'a';
while (alphabet <= 'z')
{
_putchar(alphabet);
++alphabet;
}
_putchar('\n');
}
