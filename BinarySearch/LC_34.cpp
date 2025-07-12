class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //two modified binary searches in which one will check if current is target and left is different or start and other search will look if current is target and right is different or end
        int start = 0, end = nums.size() - 1;
        vector<int> result = {-1, -1};
        // Find the leftmost index
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                // Found target, but continue searching left
                result[0] = mid;
                if (mid == 0 || nums[mid - 1] != target) {
                    // If it's the leftmost occurrence
                    break;
                }
                end = mid - 1;
            }
        } 
        start = 0, end = nums.size() - 1;
        // Find the rightmost index
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                // Found target, but continue searching right
                result[1] = mid;
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    // If it's the rightmost occurrence
                    break;
                }
                start = mid + 1;
            }
        }
        return result;
    }
};