class Solution {
public:
    bool isEmpty(unordered_map<char, int>& in_map) {
        for(auto i=in_map.begin(); i!=in_map.end(); i++) {
            if (i->second > 0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> freq_p;
        vector<int> result;
        for(char& c : p) {
            freq_p[c]++;
        }
        int n1 = s.size();
        int n2 = p.size();
        int l = 0;
        int r = 0;
        while (r < n1) {
            while (r < n1 && r-l < n2 && freq_p.find(s[r]) != freq_p.end() && freq_p[s[r]] > 0) {
                freq_p[s[r]]--;
                r++;
            }
            if (isEmpty(freq_p)) {
                result.push_back(l);
            }
            freq_p[s[l]]++;
            l++;
        }
        return result;
    }
};
