class Solution {
    int freshOranges = 0;
    int minutes = 0;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        queue<pair<int, int>> rottenOranges;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        //get the number of fresh oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                }
                else if (grid[i][j] == 2) {
                    rottenOranges.push({i, j});
                }
            }
        }
        //if there are no fresh oranges, return 0
        if (freshOranges == 0) return 0;
        //use BFS to rot the oranges, since each rotten orange can rot its adjacent fresh oranges in one minute
        //each rotted orange will do the rotting simultaneously
        while (!rottenOranges.empty()) {
            int size = rottenOranges.size();
            bool hasFresh = false; // this will help us track if any fresh orange was rotted in this minute, so that
                                  // we can increment the minutes only if at least one fresh orange was rotted
            for (int i = 0; i < size; ++i) {
                auto [x, y] = rottenOranges.front();
                rottenOranges.pop();
                for (auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; // rot the fresh orange
                        freshOranges--;
                        hasFresh = true;
                        rottenOranges.push({newX, newY});
                    }
                }
            }
            if (hasFresh) minutes++;
        }
        //if there are still fresh oranges left, return -1
        return freshOranges == 0 ? minutes : -1;

    }
};