class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = INT_MIN;
        int n = height.size();
        for(int i=n-1; i>=0; i--) {
            int curr_res = INT_MIN;
            for (int j=0;j<i;j++) {
                curr_res = max(curr_res, (i-j) * min(height[j], height[i]));
            }
            res = max(res, curr_res);
        }
        return res;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = INT_MIN;
        int n = height.size();
        int l = 0, r = n-1;
        while (l < r) {
            res = max(res, (r-l) * min(height[l], height[r]));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return res;
    }
};
