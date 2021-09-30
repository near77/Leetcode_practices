# Given an m x n matrix, return all elements of the matrix in spiral order.
# Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
# Output: [1,2,3,6,9,8,7,4,5]
# Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
# Output: [1,2,3,4,8,12,11,10,9,5,6,7]

# m == matrix.length
# n == matrix[i].length
# 1 <= m, n <= 10
# -100 <= matrix[i][j] <= 100

def spiralOrder(matrix):
    n = len(matrix[0])
    m = len(matrix)
    finished = False
    answer = []
    start = [0,0]
    while not finished:
        for i in matrix[start[0]][start[1]:n]:
            answer.append(i)
        if start[0] == m-1:
            break
        for i in range(start[0]+1, m):
            answer.append(matrix[i][n-1])
        if start[1] == n-1:
            break
        for i in matrix[m-1][n-2:start[1]:-1]:
            answer.append(i)
        for i in range(m-1, start[0], -1):
            answer.append(matrix[i][start[0]])
        m = m-1
        n = n-1
        start = [start[0]+1, start[1]+1]
        if start[0] >= len(matrix)/2 or start[1] >= len(matrix[0])/2:
            break
    return answer

matrix = [[1,2,3],[4,5,6],[7,8,9]]
print(spiralOrder(matrix))
matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
print(spiralOrder(matrix))
matrix = [[3],[2]]
print(spiralOrder(matrix))
matrix = [[6, 9 ,7]]
print(spiralOrder(matrix))
matrix = [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
print(spiralOrder(matrix))
matrix = [[2,5,8],[4,0,-1]]
print(spiralOrder(matrix))
matrix = [[2,3,4],[5,6,7],[8,9,10],[11,12,13]]
print(spiralOrder(matrix))
matrix = [[1,2],[3,4]]
print(spiralOrder(matrix))