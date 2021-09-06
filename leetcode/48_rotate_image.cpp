class Solution
{
public:
    void swapColumn(vector<vector<int> > &matrix, int col)
    {
        int n = matrix.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            swap(matrix[l][col], matrix[r][col]);
            l += 1;
            r -= 1;
        }
    }
    void rotate(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            swapColumn(matrix, i);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};