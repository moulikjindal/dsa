class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();                // Get number of rows
        int cols = mat[0].size();             // Get number of columns

        // Initialize a distance matrix with -1 (unvisited)
        vector<vector<int>> dist(rows, vector<int>(cols, -1));

        queue<pair<int, int>> q; // Queue for BFS: holds coordinates of matrix cells

        // Step 1: Push all '0' cells into the queue and set their distance as 0
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;         // Distance to nearest 0 is 0 itself
                    q.push({i, j});         // Enqueue all 0 cells as BFS starting points
                }
            }
        }

        // Step 2: Define the four possible movement directions: down, up, right, left
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 3: Perform BFS from all 0 cells simultaneously
        while (!q.empty()) {
            auto [x, y] = q.front(); // Current cell coordinates
            q.pop();

            // Explore all 4 neighbors
            for (auto& dir : dirs) {
                int newX = x + dir[0]; // Neighbor row
                int newY = y + dir[1]; // Neighbor column

                // If neighbor is within bounds and not visited yet
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && dist[newX][newY] == -1) {
                    dist[newX][newY] = dist[x][y] + 1; // Set distance as 1 more than current
                    q.push({newX, newY});              // Enqueue neighbor for further processing
                }
            }
        }

        // Return the matrix with distances to nearest 0
        return dist;
    }
};
