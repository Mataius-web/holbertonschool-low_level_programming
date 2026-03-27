#include "main.h"

/* Helper function prototype */
int sqrt_helper(int n, int guess);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 *
 * Return: natural square root, or -1 if no natural square root exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0) /* pas de racine carrée pour les nombres négatifs */
		return (-1);

	return (sqrt_helper(n, 1));
}

/**
 * sqrt_helper - helper function to find square root recursively
 * @n: number to find the square root of
 * @guess: current guess
 * Return: square root if found, -1 otherwise
 */


int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);

	return (sqrt_helper(n, guess + 1));
}
