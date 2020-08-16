class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> vec(m + 1, vector<int>(n + 1, 0));
        
        vec[0][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (!obstacleGrid[i - 1][j - 1]) {
                    vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
                }
            }
        }
        return vec[m][n];
    }
};