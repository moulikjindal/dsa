class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //LETS go to the first non-zero height
        int left = 0, right = n - 1;
        while (left < n && height[left] == 0) left++;
        while (right >= 0 && height[right] == 0) right--;

        if (left >= right) return 0; // No water can be trapped

        int leftMax = height[left], rightMax = height[right];
        int waterTrapped = 0;
        while (left < right) {
            if (leftMax < rightMax) {
                // left has a smaller height, move left pointer because it can trap water
                //if we had moved righ
                left++;
                if (height[left] < leftMax) {
                    waterTrapped += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
            } else {
                right--;
                if (height[right] < rightMax) {
                    waterTrapped += rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
            }
        }
        
        return waterTrapped;
    }
};