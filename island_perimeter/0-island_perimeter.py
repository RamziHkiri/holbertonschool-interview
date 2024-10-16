#!/usr/bin/python3
"""
Module to calculate the perimeter of an island described in a grid.

The grid is a list of lists where:
- 0 represents water.
- 1 represents land.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in the grid.

    Args:
        grid (list[list[int]]): A 2D list of integers representing the grid.
            - 0 represents water.
            - 1 represents land.

    Returns:
        int: The perimeter of the island.
    """
    val = 0
    rows = len(grid)
    cols = len(grid[0])

    def is_water(x, y):
        """
        Helper function to determine if a cell is water or out of bounds.

        Args:
            x (int): Row index of the cell.
            y (int): Column index of the cell.

        Returns:
            int: 1 if the cell is water or out of bounds, 0 otherwise.
        """
        return x < 0 or y < 0 or x >= rows or y >= cols or grid[x][y] == 0

    for column in range(rows):
        for row in range(cols):
            if grid[column][row] == 1:
                val += is_water(column - 1, row)
                val += is_water(column + 1, row)
                val += is_water(column, row + 1)
                val += is_water(column, row - 1)

    return val
