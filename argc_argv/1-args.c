#include <stdio.h>

/**
 * main - prints the number of arguments passed to the program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: 0 on success
 */


int main(int argc, char *argv[])
{
(void)argv;
printf("%d\n", argc - 1);
return (0);
}
