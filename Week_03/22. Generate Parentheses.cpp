class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        
        recursion(0, 0, n, "", vec);
        return vec;
    }
    void recursion(int left, int right, int n, string s, vector<string> &vec) {
        if (left == n && right == n) {
            vec.push_back(s);
            return;
        }
        
        if (left < n)
            recursion(left + 1, right, n, s + '(', vec);
        if (right < left )
            recursion(left, right + 1, n, s + ')', vec);
    }
};