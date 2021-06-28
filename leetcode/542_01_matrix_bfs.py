class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        queue = collections.deque()
        m = len(mat)
        n = len(mat[0])
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        dist = [[float('inf') for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dist[i][j] = 0
                    queue.append((i, j))
        while queue:
            curr_cell = queue.popleft()
            curr_row = curr_cell[0]
            curr_col = curr_cell[1]
            for direction in directions:
                new_row, new_col = curr_row + direction[0], curr_col + direction[1]
                if new_row >=0 and new_row < m and new_col >=0 and new_col < n:
                    if 1 + dist[curr_row][curr_col] < dist[new_row][new_col]:
                        dist[new_row][new_col] = 1 + dist[curr_row][curr_col]
                        queue.append((new_row, new_col))
        return dist
