class Solution {
public:
    int minPathSum_rec(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& memo) {
        int m = grid.size();
        int n = grid[0].size();
        if (row >= m || col >= n) return INT_MAX;
        if (row == m-1 && col == n-1) return grid[row][col];
        if (memo[row][col] != INT_MAX) return memo[row][col];
        memo[row][col] = grid[row][col] + min(minPathSum_rec(grid, row + 1, col, memo), minPathSum_rec(grid, row, col + 1, memo));
        return memo[row][col];
    }
    
    int minPathSum_top_down(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, INT_MAX));
        // debug(memo);
        return minPathSum_rec(grid, 0, 0, memo);
        // return memo[m-1][n-1];
    }
    
    int minPathSum_bottom_up(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long>> dp(m+1, vector<long>(n+1, INT_MAX));
        dp[1][1] = grid[0][0];
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                dp[i][j] = min(dp[i][j], min(grid[i-1][j-1] + dp[i-1][j], grid[i-1][j-1] + dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        return minPathSum_top_down(grid);
        // return minPathSum_bottom_up(grid);
    }
    
    void debug(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
