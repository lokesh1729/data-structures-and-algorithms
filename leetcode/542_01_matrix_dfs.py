class Solution:
    def dfs(self, mat, row, col, aux, visited):
        if row < 0 or row >= len(aux) or col < 0 or col >= len(aux[0]) or visited[row][col] is True:
            return float('inf')
        if mat[row][col] == 0:
            return 0
        if aux[row][col] != -1:
            return aux[row][col]
        visited[row][col] = True
        down = self.dfs(mat, row+1, col, aux, visited)
        up = self.dfs(mat, row-1, col, aux, visited)
        right = self.dfs(mat, row, col+1, aux, visited)
        left = self.dfs(mat, row, col-1, aux, visited)
        visited[row][col] = False
        result = min(down, up, right, left) + 1
        aux[row][col] = result
        return result
 
 
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        if len(mat) <= 0 or len(mat[0]) <= 0:
            return mat
        m = len(mat)
        n = len(mat[0])
        aux = [[-1 for _ in range(n)] for _ in range(m)]
        visited = [[False for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                aux[i][j] = self.dfs(mat, i, j, aux, visited)
        return aux
 
