class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n1 + n2 != n3) {
            return false;
        }
        vector<vector<int>> memo(n1, vector<int> (n2, -1));
        return isInterLeaveRecursive(s1, s2, s3, 0, 0, 0, memo);
    }
    bool isInterLeaveRecursive(string s1, string s2, string s3, int t1, int t2, int t3, vector<vector<int>>& memo) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (t1 < n1 && t2 < n2 && memo[t1][t2] > -1) {
            return !!memo[t1][t2];
        }
        if (t3 >= n3) {
            return true;
        }
        bool result = false;
        if (t1 < n1 && s1[t1] == s3[t3]) {
            result |= isInterLeaveRecursive(s1, s2, s3, t1+1, t2, t3+1, memo);
        }
        if (t2 < n2 && s2[t2] == s3[t3]) {
            result |= isInterLeaveRecursive(s1, s2, s3, t1, t2+1, t3+1, memo);
        }
        if (t1 < n1 && t2 < n2) {
            memo[t1][t2] = (int)result;
        }
        return result;
    }
};
