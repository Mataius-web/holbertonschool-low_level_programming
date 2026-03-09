#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created by alloc_grid
 * @grid: pointer to the grid
 * @height: number of rows in the grid
 */


void free_grid(int **grid, int height)
{
int i;

i = 0;
while (i < height)
{
free(grid[i]);
i++;
}

free(grid);
}
