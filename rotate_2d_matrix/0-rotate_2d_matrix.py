#!/user/bin/python3
""" rotation 2d matrice"""

def rotate_2d_matrix(matrix):
    """rotate matrice function"""
    n = len(matrix)
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in range(n):
        matrix[i].reverse()

