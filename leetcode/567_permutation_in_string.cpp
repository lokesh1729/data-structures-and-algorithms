class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        for (char& c : s1) {
            freq[c]++;
        }
        int len = s2.length();
        int windowStart = 0;
        int windowEnd = 0;
        while (windowEnd < len) {
            if (freq.find(s2[windowEnd]) != freq.end() && freq[s2[windowEnd]] > 0) {
                freq[s2[windowEnd]]--;
                windowEnd++;
                if (windowEnd - windowStart == s1.length()) {
                    return true;
                }
            } else if (windowStart == windowEnd) {
                windowStart++;
                windowEnd++;
            } else {
                freq[s2[windowStart]]++;
                windowStart++;
            }
        }
        return false;
    }
};
