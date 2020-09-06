class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxL = 0;
        stk.push(-1);
        
        for (int i = 0; i < s.size(); i++) {
            int t = stk.top();
            if (t != -1 && s[i] == ')' && s[t] == '(') {
                stk.pop();
                maxL = max(maxL, i - stk.top());
            }
            else {
                stk.push(i);
            }
        }
        return maxL;
    }
};