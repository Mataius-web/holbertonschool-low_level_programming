#include "main.h"

/**
 *swap_int - swap value of 2 variables int
 * @a: first variable
 * @b: second variable
 */

void swap_int(int *a, int *b)
{
int swap;

swap = *a;
*a = *b;
*b = swap;
}
