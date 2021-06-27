class Solution {
public:
    int lengthofLISRecursive(vector<int>& nums, int index, int curr_val, map<int,int>& memo) {
        int res = 0;
        int n = nums.size();
        if (index >= n) {
            return 0;
        }
        if (memo.find(index) != memo.end()) {
            return memo.find(index)->second;
        }
        for(int i=index + 1;i<n;i++) {
            if (nums[i] <= curr_val) {
                continue;
            }
            res = max(res, 1 + lengthofLISRecursive(nums, i, nums[i], memo));
        }
        memo[index] = res;
        return memo[index];
    }
    int lengthOfLIS_top_down(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        map<int, int> memo;
        for(int i=0;i<n;i++) {
            res = max(res, 1 + lengthofLISRecursive(nums, i, nums[i], memo));
        }
        return res;
    }
    int lengthOfLIS_iterative(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        // vector<vector<int>(n, 0)>> table(n, 0);
        // This does not work for [0,1,0,3,2,3]
        // especially at 3,2,3
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int curr_res = 1;
                int curr = nums[i];
                for(int k=j; k<n; k++) {
                    if (nums[k] > curr) {
                        curr = nums[k];
                        curr_res += 1;
                    }
                }
                res = max(res, curr_res);
            }
        }
        return res;
    }
    int lengthOfLIS_bottom_up(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 1;
        for(int i=n-2; i>=0; i--) {
            int curr = 1;
            for(int j=i+1; j<n; j++) {
                if (nums[j] > nums[i]) {
                    curr = max(curr, 1 + dp[j]);
                }
            }
            dp[i] = curr;
        }
        int res = INT_MIN;
        for (int i=0; i<(int)dp.size(); i++) {
            res = max(dp[i], res);
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLIS_bottom_up(nums);
    }
};
