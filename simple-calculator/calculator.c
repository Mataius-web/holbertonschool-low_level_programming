#include <stdio.h>

/**
 * main - display the menu
 * Return: 0 succes
 */

int main(void)
{

int userComand;

printf("Simple Calculator\n");
printf("1) Add\n");
printf("Subtract\n");
printf("3) Multiply\n");
printf("4) Divide\n");
printf("0) Quit\n");
printf("Choice: ");
scanf("%d", &userComand);
if (userComand == 0)
{
printf("Bye!\n");
return (0);
}
else
{
return (0);
}
}
