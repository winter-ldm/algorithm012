class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> vec(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (text1[i - 1] == text2[j - 1])
                    vec[i][j] = vec[i - 1][j - 1] + 1;
                else 
                    vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]);
        return vec[m][n];
    }
};