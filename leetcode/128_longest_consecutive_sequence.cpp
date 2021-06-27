class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int result = 0;
        for(int& num : nums) {
            int c = 1;
            int curr = num;
            while(s.find(--curr) != s.end()) {
                c++;
                s.erase(curr);
            }
            curr = num;
            while(s.find(++curr) != s.end()) {
                c++;
                s.erase(curr);
            }
            result = max(result, c);
        }
        return result;
    }
};
