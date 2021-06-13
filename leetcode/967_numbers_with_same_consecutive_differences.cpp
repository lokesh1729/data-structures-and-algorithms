class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr_result;
        for(int i=1;i<10;i++) {
             curr_result.push_back(i);
             numsSameConsecDiffRecursive(n, k, i, curr_result, result);
             curr_result.pop_back();
        }
        vector<int> res;
        for (vector<int>& vc : result) {
            int temp = 0;
            int mul = 1;
            for (int i=vc.size()-1;i>=0;i--) {
                temp = (mul * vc[i]) + temp;
                mul *= 10;
            }
            res.push_back(temp);
        }
        return res;
    }
    void numsSameConsecDiffRecursive(int n, int k, int target, vector<int> curr_result, vector<vector<int>>& result) {
        if (curr_result.size() == n) {
            result.push_back(curr_result);
            return;
        }
        if (k==0) {
            curr_result.push_back(target);
            numsSameConsecDiffRecursive(n, k, target, curr_result, result);
            curr_result.pop_back();
        } else {
            if (target+k < 10) {
                curr_result.push_back(target+k);
                numsSameConsecDiffRecursive(n, k, target+k, curr_result, result);
                curr_result.pop_back();
            }
            if (target-k >= 0) {
                curr_result.push_back(target-k);
                numsSameConsecDiffRecursive(n, k, target-k, curr_result, result);
                curr_result.pop_back();
            }
        }
    }
};
