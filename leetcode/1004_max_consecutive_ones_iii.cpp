class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int count = 0;
        int res = INT_MIN;
        for(int r=0;r<n;r++) {
            if (nums[r] == 0) count++;
            while (count > k) {
                if (nums[l] == 0) count--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
