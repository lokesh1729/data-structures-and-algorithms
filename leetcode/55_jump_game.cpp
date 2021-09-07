class Solution {
public:
    bool canJump_bfs(vector<int>& nums) {
        int n = nums.size();
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int jumpLen = q.front();
            q.pop();
            if (jumpLen + 1 >= n) {
                return true;
            }
            for (int j=1; j<=nums[jumpLen]; j++) {
                q.push(j + jumpLen);
            }
        }
        return false;
    }

    bool canJump_top_down_dp(vector<int>& nums, int pos, unordered_map<int, bool>& umap) {
        int n = nums.size();
        if (pos >= n-1) return true;
        if (umap.find(pos) != umap.end()) return umap[pos];
        bool result = false;
        for (int i=1; i<=nums[pos]; i++) {
            result |= canJump_top_down_dp(nums, i + pos, umap);
        }
        return umap[pos] = result;
    }

    bool canJump(vector<int>& nums) {
        // unordered_map<int, bool> umap;
        // return canJump_top_down_dp(nums, 0, umap);
        // return canJump_bfs(nums);
        // canJump_bfs2(nums);
        return canJump_best(nums);
    }

    bool canJump_best(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        if (n == 1) {
            return true;
        }
        if (n <= 0 || nums[0] == 0) {
            return false;
        }
        int maxReachable = 0;
        for (int i=0; i<n; i++) {
            if (maxReachable >= n-1) {
                return true;
            }
            if (maxReachable == i && nums[i] == 0) {
                return false;
            }
            maxReachable = max(maxReachable, i + nums[i]);
        }
        return false;
    }

    bool canJump_bfs2(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int maxReachable = 0, currPos = 0, i = 0, n = nums.size();
        if (n == 1) {
            return true;
        }
        if (n <= 0 || nums[0] == 0) {
            return false;
        }
        while (i < n-1) {
            maxReachable = max(maxReachable, i + nums[i]);
            if (maxReachable + 1 >= n) {
                return true;
            }
            if (i == currPos) {
                if (currPos == maxReachable) {
                    break;
                }
                currPos = maxReachable;
            }
            i++;
        }
        return false;
    }
};
