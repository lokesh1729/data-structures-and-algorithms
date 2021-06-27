class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> result(n, -1);
        result[n-1] = 0;
        s.push(n-1);
        for(int i=n-2; i >= 0; i--) {
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            if (s.empty()) {
                result[i] = 0;
            } else {
                result[i] = s.top() - i;
            }
            s.push(i);
        }
        return result;
    }
};
