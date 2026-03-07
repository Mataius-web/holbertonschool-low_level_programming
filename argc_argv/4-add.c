#include <stdio.h>
#include <stdlib.h>

/**
 * is_valid - checks if a string contains only digits
 * @str: the string to check
 * Return: 1 if valid, 0 otherwise
 */


int is_valid(char *str)
{
int i;

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] < '0' || str[i] > '9')
return (0);
}
return (1);
}

/**
 * main - adds positive numbers passed as command line arguments
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: 0 on success, 1 on error
 */


int main(int argc, char *argv[])
{
int i, sum;

if (argc == 1)
{
printf("0\n");
return (0);
}
sum = 0;
for (i = 1; i < argc; i++)
{
if (!is_valid(argv[i]))
{
printf("Error\n");
return (1);
}
sum += atoi(argv[i]);
}
printf("%d\n", sum);
return (0);
}
