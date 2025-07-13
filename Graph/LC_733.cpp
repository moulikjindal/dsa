class Solution {
private:
    int originalColor;
    int newColor;
    int rows, cols;

    void dfs(vector<vector<int>>& image, int sr, int sc) {
        if (sr < 0 || sr >= rows || sc < 0 || sc >= cols || image[sr][sc] != originalColor) {
            return;
        }
        
        image[sr][sc] = newColor;

        // Explore all four directions
        dfs(image, sr + 1, sc); // Down
        dfs(image, sr - 1, sc); // Up
        dfs(image, sr, sc + 1); // Right
        dfs(image, sr, sc - 1); // Left
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.empty() || image[0].empty()) {
            return image; // Handle empty image case
        }

        rows = image.size();
        cols = image[0].size();
        originalColor = image[sr][sc];
        newColor = color;

        if (originalColor != newColor) { // Only proceed if the color is different
            dfs(image, sr, sc);
        }

        return image;
    }
};