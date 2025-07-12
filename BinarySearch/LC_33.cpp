class Solution {
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Target not found
    }
public:
    int search(vector<int>& nums, int target) {
        //finding the pivot point
        if (nums.empty()) return -1;
        if(nums.size() == 1) return nums[0] == target ? 0 : -1;
        if(nums[0] < nums.back()) {
            // Array is not rotated, perform normal binary search
            return binarySearch(nums, 0, nums.size() - 1, target);
        }
        //now we have to find the pivot point
        int left = 0, right = nums.size() - 1;
        while (nums[left] > nums[right]) {
            int mid = left + (right - left) / 2;
            // Check if mid is the pivot
            if (mid < right && nums[mid] > nums[right]) {
                left = mid + 1; // Move to the right side
            } else if (mid > left && nums[mid] < nums[left]) {
                right = mid; // Move to the left side
            } else {
                break; // Found the pivot
            }
        }
        // left is now the index of the smallest element (pivot)
        int pivot = left;
        // Now we have two sorted subarrays: [0, pivot-1] and [pivot, n-1]
        if (target >= nums[pivot] && target <= nums.back()) {
            // Search in the right subarray
            return binarySearch(nums, pivot, nums.size() - 1, target);
        } else {
            // Search in the left subarray
            return binarySearch(nums, 0, pivot - 1, target);
        }
        return -1; // Target not found
    }
};