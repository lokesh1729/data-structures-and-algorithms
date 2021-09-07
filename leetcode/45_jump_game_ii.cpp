class Solution
{
public:
    int jump_myapproach(vector<int> &nums)
    {
        int res = INT_MAX;
        int n = nums.size();
        if (n == 1)
        { // you already at end
            return 0;
        }
        queue<pair<int, int> > q;
        q.push({0, 0});
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 1; i <= nums[curr.first]; i++)
            {
                if (curr.first + i + 1 >= n)
                {
                    res = min(res, curr.second + 1);
                }
                else
                {
                    q.push({curr.first + i, curr.second + 1});
                }
            }
        }
        return res;
    }
    int jump_bfs1(vector<int> &nums)
    {
        int n = nums.size(), level = 0, i = 0, currMax = 0, nextMax = 0;
        if (n <= 1)
        {
            return 0;
        }
        while (true)
        {
            level++;
            for (; i <= currMax; i++)
            {
                nextMax = max(nextMax, nums[i] + i);
                if (nums[i] + i + 1 >= n)
                {
                    return level;
                }
            }
            currMax = nextMax;
        }
        return -1;
    }
    int jump_dp(vector<int> &nums)
    {
        int n = nums.size();
        int dp[1001];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (nums[j] < i)
                {
                    continue;
                }
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }
    int jump_dp2(vector<int> &nums)
    {
        int n = nums.size();
        int dp[1001];
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i++)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                dp[i] = min(dp[i], 1 + dp[min(n - 1, i + j)]);
            }
        }
        return dp[0];
    }
    int jump_bfs_greedy(vector<int> &nums)
    {
        int n = nums.size();
        int curr_pos = 0, max_reachable = 0, i = 0, jumps = 0;
        while (curr_pos < n - 1)
        {
            max_reachable = max(max_reachable, i + nums[i]);
            if (i == curr_pos)
            {
                jumps++;
                curr_pos = max_reachable;
            }
            i++;
        }
        return jumps;
    }
    int jump(vector<int> &nums)
    {
        // return jump_bfs1(nums);
        return jump_bfs_greedy(nums);
    }
};