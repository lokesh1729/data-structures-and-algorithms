class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        letterCombinationsRecurisve(digits, vector<string>{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, 0, vector<char>{}, res);
        return res;
    }
    void letterCombinationsRecurisve(string digits, vector<string> map, int index, vector<char> curr_res, vector<string>& res) {
        if (index >= (int)digits.size()) {
            string r = "";
            for(char& s : curr_res) {
                r += s;
            }
            res.push_back(r);
            return;
        }
        string s = map[digits[index] - '0'];
        for(int i=0; i<(int)s.size(); i++) {
            curr_res.push_back(s[i]);
            letterCombinationsRecurisve(digits, map, index+1, curr_res, res);
            curr_res.pop_back();
        }
    }
};
