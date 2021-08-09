class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return {};
        }
        vector<string> res;
        // stack<char> st;
        // generateParenthesis_Recursive(res, "", st, n, 0);
        bfs(res, n);
        return res;
    }
    void generateParenthesis_Recursive(vector<string>& res, string curr_res, stack<char> st, int n, int curr_count) {
        if (curr_res.size() == n * 2 && st.empty()) {
            res.push_back(curr_res);
            return;
        }
        if (st.empty() || (st.size() + curr_count < n)) {
            st.push('(');
            generateParenthesis_Recursive(res, curr_res + "(", st, n, curr_count);
            st.pop();
        }
        if (!st.empty()) {
            st.pop();
            generateParenthesis_Recursive(res, curr_res + ")", st, n, curr_count + 1);
        }
        return;
    }
    struct Pair {
        string bracket;
        int left;
        int right;
        Pair(string bracket, int left, int right) {
            this->bracket = bracket;
            this->left = left;
            this->right = right;
        }
    };
    void bfs(vector<string>& res, int n) {
        queue<Pair> q;
        q.push(Pair("", 0, 0));
        while (!q.empty()) {
            Pair curr = q.front();
            q.pop();
            if (curr.left == n &&  curr.right == n) {
                res.push_back(curr.bracket);
            } else {
                if (curr.left < n) {
                    q.push(Pair(curr.bracket + "(", curr.left + 1, curr.right));
                } if (curr.right < curr.left) {
                    q.push(Pair(curr.bracket + ")", curr.left, curr.right + 1));
                }
            }
         }
    }
};
