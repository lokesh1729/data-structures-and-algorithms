class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // return solution_one(s);
        return my_solution(s);
    }

    int my_solution(string s) {
        int n = s.size();
        unordered_map<char, int> occurrences;
        int l=0, r=0, res=0;
        for (;r<n; r++) {
            if (occurrences.find(s[r]) != occurrences.end() && occurrences.find(s[r])->second >= l) {
            // if (occurrences.find(s[r]) != occurrences.end()) {
                // while (occurrences.find(s[r]) != occurrences.end()) {
                //     occurrences.erase(s[l]);
                //     l++;
                // }
                l = occurrences[s[r]] + 1;
            }
            res = max(res, r-l+1);
            occurrences[s[r]] = r;
        }
        // if (l != r) {
        //     res = max(res, r-l);
        // }
        return res;
    }

    int solution_one(string s) {
        int n = s.size();
        int l=0, r=0;
        int res=0;
        vector<int> arr(128, 0);
        while (r < n) {
            arr[(int)s[r]]++;
            while (arr[(int)s[r]] > 1) {
                arr[(int)s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
	    }
        return res;
    }
};
