class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, vector<int>> m1;
        map<char, vector<int>> m2;
        for (int i=0; i < (int)s.size(); i++) {
            m1[s[i]].push_back(i);
        }
        for (int i=0; i < (int)t.size(); i++) {
            m2[t[i]].push_back(i);
        }
        if (m1.size() != m2.size()) return false;
        int l=0, r=0;
        while (l < (int) s.size() && r < (int) t.size()) {
            if (m1.find(s[l])->second != m2.find(t[r])->second) return false;
            l++;
            r++;
        }
        return true;
    }
};
