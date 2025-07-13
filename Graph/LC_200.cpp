class Solution {
    vector<vector<char>> gridd;
    int rows, cols;
    void dfs(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || gridd[i][j] == '0') {
            return;
        }
        gridd[i][j] = '0'; // Mark as visited
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();
        gridd = grid;
        int islandCount = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (gridd[i][j] == '1') {
                    dfs(i, j);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};