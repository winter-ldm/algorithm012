class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    recursion(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }
    void recursion(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[i].size() - 1 || grid[i][j] == '0')
            return ;
        grid[i][j] = '0';
        recursion(grid, i - 1, j);
        recursion(grid, i + 1, j);
        recursion(grid, i, j - 1);
        recursion(grid, i, j + 1);
    }
};