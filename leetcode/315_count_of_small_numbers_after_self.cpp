class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> new_nums(n);
        for(int i=0;i<n;i++) {
            new_nums[i] = {nums[i], i};
        }
        vector<int> result(n, 0);
        mergeSort(new_nums, 0, n-1, result);
        return result;
    }
    void mergeSort(vector<pair<int, int>>& nums, int low, int high, vector<int>& result) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid, result);
        mergeSort(nums, mid+1, high, result);
        vector<pair<int, int>> aux;
        int left = low;
        int right = mid + 1;
        int count = 0;
        while (right <= high && left <= mid) {
            if (nums[right].first < nums[left].first) {
                count++;
                aux.push_back(nums[right++]);
            } else {
                result[nums[left].second] += count;
                aux.push_back(nums[left++]);
            }
        }
        while (left <= mid) {
            result[nums[left].second] += count;
            aux.push_back(nums[left++]);
        }
        while (right <= high) {
            aux.push_back(nums[right++]);
        }
        int curr_ptr = low;
        for(pair<int,int>& val : aux) {
            nums[curr_ptr] = val;
            curr_ptr++;
        }
    }
};
