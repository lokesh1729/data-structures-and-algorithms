class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        map<int, bool> memo;
        if (s[s.size() - 1] != '0') {
            return false;
        }
        return canReachRecursive(s, minJump, maxJump, 0, memo);
    }
    bool canReachRecursive(string s, int minJump, int maxJump, int index, map<int, bool>& memo) {
        int n = (int) s.size();
        if (memo.find(index) != memo.end()) return memo.find(index) -> second;
        if (index == n - 1 && s[index] == '0') return true;
        if (s[index] != '0') return false;
        bool result = false;
        for(int i = index + minJump; i <= min(index + maxJump, n-1); i++) {
            result |= canReachRecursive(s, minJump, maxJump, i, memo);
        }
        memo[index] = result;
        return memo[index];
    }
};
