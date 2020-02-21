#!/usr/bin/python3

""" Function to find perimiter of an island """


def island_perimeter(grid):
    """
    Input: List of Lists
    Returns: Perimeter of the island
    """
    count = 0
    row = len(grid)
    col = len(grid[0]) if row else 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):

            idx = [(i - 1, j), (i, j - 1), (i, j + 1), (i + 1, j)]
            check = all([1 if k[0] in range(row) and k[1] in range(col) else 0
                         for k in idx])

            if check and grid[i][j]:
                count += sum([1 if not grid[k[0]][k[1]] else 0 for k in idx])

    return (count)
