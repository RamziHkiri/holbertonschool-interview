#include "sandpiles.h"

/**
 * sandpiles_sum - Add grid2 to grid1 and make sure is a stable sandpile
 * @grid1: First sandpile
 * @grid2: Second sandpile
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)	
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (eval_is_stable(grid1) != TRUE)
	{
		printf("=\n");
		prn_grid(grid1);
		do_toppling_round(grid1);
	}
}

/**
 * eval_is_stable- Evaluate if sadpile is stable
 * @grid1: The sandpile
 * Return: [ TRUE | FALSE ]
 */
int eval_is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				return (FALSE);

	return (TRUE);
}

/**
 * do_toppling_round - Do the toppling round to the sandpile
 * @grid1: The sandpile
 * Return: Nothing
 */
void do_toppling_round(int grid1[3][3])
{
	int i = 0, j = 0;

	oper_celd(grid1, i, j, INIT);
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			oper_celd(grid1, i, j, CALC);
}


/**
 * oper_celd - Evaluate what operations are needed arround the cell
 * @grid1: The grid
 * @i: Row
 * @j: Column
 * @cmd: Command
 */
void oper_celd(int grid1[3][3], int i, int j, char cmd)
{
	static int grid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int r, c;

	if (cmd == INIT)
	{
		for (r = 0; r < 3; r++)
			for (c = 0; c < 3; c++)
				grid[r][c] = grid1[r][c];
		return;
	}
	if (grid[i][j] <= 3)
		return;
	if (i == 0)
		grid1[i][j]--;
	else
		if (grid[i - 1][j] <= 3)
			grid1[i][j]--, grid1[i - 1][j]++;
	if (j == 2)
		grid1[i][j]--;
	else
		if (grid[i][j + 1] <= 3)
			grid1[i][j]--, grid1[i][j + 1]++;
	if (i == 2)
		grid1[i][j]--;
	else
		if (grid[i + 1][j] <= 3)
			grid1[i][j]--, grid1[i + 1][j]++;
	if (j == 0)
		grid1[i][j]--;
	else
		if (grid[i][j - 1] <= 3)
			grid1[i][j]--, grid1[i][j - 1]++;
}

/**
 * prn_grid - print the grid
 * @grid: The grid
 * Return: Nothing
 */
void prn_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}