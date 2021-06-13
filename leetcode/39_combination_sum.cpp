class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr_result;
        combinationSumRecursive(candidates, result, curr_result, target, 0);
        return result;
    }

    void combinationSumRecursive(vector<int>& candidates, vector<vector<int>>& result, vector<int>& curr_result, int target, int start) {
        if (target == 0) {
            result.push_back(curr_result);
            return;
        }
        for(int i=start; i < candidates.size() && candidates[i] <= target ; i++) {
            curr_result.push_back(candidates[i]);
            combinationSumRecursive(candidates, result, curr_result, target-candidates[i], i);
            curr_result.pop_back();
        }
    }
};
