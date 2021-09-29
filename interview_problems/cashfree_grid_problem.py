"""

[[], [], []]

"""

def find_path_recursive(grid, i, j):
    m = len(grid)
    n = len(grid[0])
    if (i >= m or j >= n):
        return []
    if i == m-1 and j == n-1:
        return [(i, j)]
    if grid[i][j] == 0:
        return []
    down = find_path_recursive(grid, i+1, j)
    right = find_path_recursive(grid, i, j+1)
    if not (down or right):
    	return []
    new_path = [(i,j)]
    if down and right:
    	return [new_path + down, new_path + right]
    elif down:
    	new_path = [new_path + down]
    elif right:
    	new_path = [new_path + right]
    return new_path

def find_path(grid):
	return find_path_recursive(grid, 0, 0)


if __name__ == "__main__":
	grid = [
		[1, 0, 1, 1],
		[1, 1, 1, 0],
		[0, 1, 1, 1],
		[1, 1, 1, 1],
	]
	print(find_path(grid))
