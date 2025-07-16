class Solution {

public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        int m = heights.size();
        int n = heights[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) return;
        visited[i][j] = true;
        //check all four directions 
        if (i > 0 && heights[i - 1][j] >= heights[i][j]) dfs(heights, visited, i - 1, j); //check the upper cell if its value is greater than or equal to the current cell
        if (i < m - 1 && heights[i + 1][j] >= heights[i][j]) dfs(heights, visited, i + 1, j);
        if (j > 0 && heights[i][j - 1] >= heights[i][j]) dfs(heights, visited, i, j - 1);
        if (j < n - 1 && heights[i][j + 1] >= heights[i][j]) dfs(heights, visited, i, j + 1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int m = heights.size();
        if (m == 0) return result;
        int n = heights[0].size();
        if (n == 0) return result;
        vector<vector<bool>> pacific(m, vector<bool>(n, false)); //to check if the cell can flow to the pacific ocean
        vector<vector<bool>> atlantic(m, vector<bool>(n, false)); //to check if the cell can flow to the atlantic ocean
        //check for the pacific ocean
        for (int i = 0; i < m; i++) { //check the first and last column
            dfs(heights, pacific, i, 0); //check the first column
            dfs(heights, atlantic, i, n - 1); //check the last column
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        //now check for the cells that can flow to both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
        
    }
};

/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 */