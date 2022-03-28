def dfs(grid, i, j, curr_path, result):
	m = len(grid)
	n = len(grid[0])
	if i < 0 or j < 0 or i >= m or j >= n or grid[i][j] == 1:
		return
	if i == m-1 and j == n-1:
		result.append(curr_path + [(i, j)])
		return
	grid[i][j] = 1
	dfs(grid, i, j+1, curr_path + [(i, j)], result)
	dfs(grid, i, j-1, curr_path + [(i, j)], result)
	dfs(grid, i-1, j, curr_path + [(i, j)], result)
	dfs(grid, i+1, j, curr_path + [(i, j)], result)
	grid[i][j] = 0



def find_path(grid):
	m = len(grid)
	n = len(grid[0])
	result = []
	dfs(grid, 0, 0, [], result)
	return result


if __name__ == "__main__":
	grid = [
		[ 0, 0, 1, 1, 1],
		[ 0, 0, 0, 1, 1],
		[ 1, 1, 0, 1, 1],
		[ 1, 1, 0, 0, 1],
		[ 1, 1, 1, 0, 0],
	]
	print(find_path(grid))

# [[(0, 0), (0, 1), (1, 1), (1, 2), (2, 2), (3, 2), (3, 3), (4, 3), (4, 4)]]

# [[(0, 0), (0, 1), (1, 1), (1, 2), (2, 2), (3, 2), (3, 3), (4, 3), (4, 4)], [(0, 0), (1, 0), (1, 1), (1, 2), (2, 2), (3, 2), (3, 3), (4, 3), (4, 4)]]

