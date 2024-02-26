#ifndef SANDPLIE
#define SANDPLIE

#include <stdio.h>

#define ERROR -1
#define FALSE  0
#define TRUE   1

#define INIT 0
#define CALC 1

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int eval_is_stable(int grid1[3][3]);
void do_toppling_round(int grid1[3][3]);
void oper_celd(int grid1[3][3], int i, int j, char cmd);
void prn_grid(int grid[3][3]);

#endif 