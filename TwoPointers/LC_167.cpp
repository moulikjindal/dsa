class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2);
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                result[0] = left + 1; // Convert to 1-based index
                result[1] = right + 1; // Convert to 1-based index
                return result;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return result; // In case no solution is found, though the problem guarantees one
        
    }
};