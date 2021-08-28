class Solution {
public:
    int firstMissingPositive_my_approach(vector<int>& nums) {
        // long int curr_max = INT_MIN;
        // for(int& val : nums) {
        //     if (val > curr_max) {
        //         curr_max = val;
        //     }
        // }
        cout << INT_MAX << endl;
        vector<int> arr(INT_MAX, 0);
        for (int& val : nums) {
            if (val < 0 || val == INT_MAX) continue;
            arr[val] += 1;
        }
        for (int i=1; i<INT_MAX; i++) {
            if (arr[i] == 0) {
                return i;
            }
        }
        // int x = 1;
        // while (true) {
        //     if (find(nums.begin(), nums.end(), x) == nums.end()) {
        //         return x;
        //     }
        //     x += 1;
        // }
        return -1;
    }

    int firstMissingPositive_with_space(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1, 0);
        for (int& val:nums) {
            if (val < 0 || val > n) continue;
            arr[val] += 1;
        }
        for (int i=1; i<=n; i++ ) {
            if (arr[i] == 0) {
                return i;
            }
        }
        return n+1;
    }

    int firstMissingPositive_without_space(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i=0; i<n; i++) {
            if (nums[i] != i+1) {
                return i + 1;
            }
        }
        return n + 1;
    }

    int firstMissingPositive_without_space_2(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        for (int i=0; i<n; i++) {
            int val = abs(nums[i]);
            if (val > n) {
                continue;
            }
            val--;
            if (nums[val] > 0) {
                nums[val] = -1 * nums[val];
            }
        }
        for (int i=0; i<n; i++) {
            if (nums[i] >= 0) {
                return i+1;
            }
        }
        return n+1;
    }

    int firstMissingPositive(vector<int>& nums) {
        // return firstMissingPositive_without_space(nums);
        return firstMissingPositive_without_space_2(nums);
    }
};
