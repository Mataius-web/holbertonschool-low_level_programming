#include <stdio.h>

/**
 * main - prints all arguments received by the program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: 0 on success
 */


int main(int argc, char *argv[])
{
int i;

for (i = 0; i < argc; i++)
printf("%s\n", argv[i]);
return (0);
}
