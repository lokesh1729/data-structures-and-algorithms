struct compare{
    bool operator() (pair<int, int> a, pair<int, int> b){
         return !(a.second > b.second);
    }
};

struct compare2 {
    bool operator() (vector<int> a, vector<int> b) {
         if (a[0] != b[0]) {
             return !(a[0] > b[0]);
         } if (a[1] != b[1]) {
             return !(a[1] < b[1]);
         }
         return false;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare2());
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
        vector<vector<int>> result;
        q.push({intervals[0][0], intervals[0][1]});
        for(int i=1; i<n; i++) {
            if (!q.empty() && intervals[i][0] <= q.top().second) {
                if (intervals[i][1] > q.top().second) {
                    pair<int, int> curr = q.top();
                    q.pop();
                    q.push({curr.first, intervals[i][1]});
                }
            } else {
                q.push({intervals[i][0], intervals[i][1]});
            }
        }
        while (!q.empty()) {
            pair<int, int> curr = q.top();
            q.pop();
            vector<int> t = vector<int>{curr.first, curr.second};
            result.push_back(t);
        }
        return result;
    }
};
