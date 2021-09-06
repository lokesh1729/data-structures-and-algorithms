class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // return groupAnagrams_myapproach(strs);
        return groupAnagrams_best_case(strs);
    }
    
    vector<vector<string>> groupAnagrams_best_case(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> umap;
        for(string& s : strs) {
            string t = s;
            sort(s.begin(), s.end());
            umap[s].push_back(t);
        }
        unordered_map<string, vector<string>>::iterator it = umap.begin();
        while (it != umap.end()) {
            result.push_back(it->second);
            it++;
        }
        return result;
    }
    
    vector<vector<string>> groupAnagrams_myapproach(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        vector<bool> visited(n, false);
        vector<vector<int>> aux(n, vector<int> (26, 0));
        for (int i=0; i<n; i++) {
            for (char& c: strs[i]) {
                aux[i][c - 'a'] += 1;
            }
        }
        for (int i=0; i<n; i++) {
            if (visited[i]) {
                continue;
            }
            vector<string> temp;
            temp.push_back(strs[i]);
            for (int j=i+1; j<n; j++) {
                if (isAnagram(strs[i], strs[j], i, j, aux)) {
                    visited[j] = true;
                    temp.push_back(strs[j]);
                }
            }
            res.push_back(temp);
            visited[i] = true;
        }
        return res;
    }
    
    bool isAnagram(string& a, string& b, int a_idx, int b_idx, vector<vector<int>>& aux) {
        if (a.size() != b.size()) {
            return false;
        }
        int n = a.size();
        for (int i=0; i<n; i++) {
            if (aux[a_idx][a[i] - 'a'] != aux[b_idx][a[i] - 'a']) {
                return false;
            }
        }
        return true;
    }
};