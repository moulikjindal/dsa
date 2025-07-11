class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2; // To prevent overflow
            
            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[left] == target) {
                return left; // Target found at left
            } else if (nums[right] == target) {
                return right; // Target found at right
            } else if (nums[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        return -1; // Target not found
    }
};