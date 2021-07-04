class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        vector<vector<int>> res;
        while(r < n) {
            if(s[l] == s[r]) {
                r++;
            } else {
                if (r-l >= 3) {
                    res.push_back({l, r-1});
                    l = r-1;
                }
                l++;
            }
        }
        if (r-l >= 3) res.push_back({l, r-1});
        return res;
    }
};
