class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int left =0;
        int right =0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = min(height[i], height[j]) * (j - i);
                maxi = max(maxi, area);
            }
        }
    }
};

#include <vector>
#include <algorithm> // For std::min and std::max

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Calculate the width of the container
            int width = right - left;
            
            // Calculate the height of the container (limited by the shorter line)
            int current_height = std::min(height[left], height[right]);
            
            // Calculate the area for the current pair of lines
            int current_area = width * current_height;
            
            // Update the maximum area found so far
            max_area = std::max(max_area, current_area);
            
            // --- The core logic for moving the pointers ---
            // Move the pointer that points to the shorter line inward.
            // Why? Because the shorter line is the bottleneck for the area.
            // Moving the taller line's pointer would only decrease the width 
            // without any chance of increasing the container's height, 
            // thus guaranteeing a smaller area.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};