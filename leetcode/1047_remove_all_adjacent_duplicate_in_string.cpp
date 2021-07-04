class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for(char& a:s) {
            if (!stack.empty() && stack.top() == a) {
                stack.pop();
            } else {
                stack.push(a);
            }
        }
        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};
