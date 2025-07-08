class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int positiveStart = 0;
        while (positiveStart < n && nums[positiveStart] < 0) {
            positiveStart++;
        }
        int negativeEnd = positiveStart - 1;
        vector<int> result(n);
        int index = 0;
        while (negativeEnd >= 0 && positiveStart < n) {
            if (abs(nums[negativeEnd]) < abs(nums[positiveStart])) {
                result[index++] = nums[negativeEnd] * nums[negativeEnd];
                negativeEnd--;
            } else {
                result[index++] = nums[positiveStart] * nums[positiveStart];
                positiveStart++;
            }
        }
        while (negativeEnd >= 0) {
            result[index++] = nums[negativeEnd] * nums[negativeEnd];
            negativeEnd--;
        }
        while (positiveStart < n) {
            result[index++] = nums[positiveStart] * nums[positiveStart];
            positiveStart++;
        }
        return result;
        
    }
};