#!/usr/bin/python3
"""
Module to calculate the perimeter of an island described in a grid.

The grid is represented by a list of lists, where:
- 0 represents water.
- 1 represents land.

The function calculates the perimeter of the island by checking each land cell and counting how many edges are either adjacent to water or out of bounds.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in the grid.

    Args:
        grid (list[list[int]]): A 2D list representing the grid where:
            - 0 represents water.
            - 1 represents land.

    Returns:
        int: The perimeter of the island.

    The function checks every land cell in the grid and increases the perimeter for
    each adjacent water cell or if the cell is at the grid boundary.

    Example:
        grid = [
            [0, 1, 0, 0],
            [1, 1, 1, 0],
            [0, 1, 0, 0],
            [1, 1, 0, 0]
        ]
        island_perimeter(grid)  # returns 16
    """

    perimeter = 0
    m = len(grid)  # Number of rows
    n = len(grid[0])  # Number of columns

    # Loop through each cell in the grid
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:  # Only consider land cells
                # Check four possible directions (up, down, left, right)
                for x, y in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
                    a, b = i + x, j + y
                    # Add to perimeter if out of bounds or adjacent to water
                    if a >= m or b >= n or a < 0 or b < 0 or grid[a][b] == 0:
                        perimeter += 1

    return perimeter
