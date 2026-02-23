#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - set a random number into n
 * and print if the number is negative, positive or strictly 0
 * Return: 0 if the program run
 */

int main(void)
{
int n;

srand(time(0));
n = rand() - RAND_MAX / 2;
if (n > 0)
{
printf("%d is positive\n", n);
}
else if (n == 0)
{
printf("%d is zero\n", n);
}
else
{
printf("%d is negative\n", n);
}
return (0);
}
