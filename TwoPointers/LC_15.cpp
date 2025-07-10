class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> numCount;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // the required sum is -num
            int target = -nums[i];
            // skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            //use 2 pointers to find pairs that sum to target and when found add the triplet to result
            int left = i+1, right = nums.size() - 1;
            while (left < right) {
                if (left == i) {
                    left++;
                    continue;
                }
                if (right == i) {
                    right--;
                    continue;
                }
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // skip duplicates for the second number
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // skip duplicates for the third number
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }

        }
        return result;

    }
};

/*
Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 10^5
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> numCount;
        vector<vector<int>> result;
        for (int num : nums) {
            numCount[num]++;
        }
        int n = nums.size();
        //now we can just to go to every item in the map and decrement the count of the number 
        //then for this number , we go to every item in the map again, decrement that number count, and check if the sum of the two numbers, which will be sum, and we can check that -sum exists in has map, if it does good otherwise, increment count and move on
        for (auto& [num, count] : numCount) {
            if (count == 0) continue; // skip if the number is already used
            numCount[num]--;
            for (auto& [num2, count2] : numCount) {
                if (count2 == 0 || num == num2) continue; // skip if the number is already used or same as first number
                numCount[num2]--;
                int sum = -(num + num2);
                if (numCount[sum] > 0) { // check if the third number exists
                    //add the triplet sorted in ascending order
                    vector<int> triplet = {num, num2, sum};
                    sort(triplet.begin(), triplet.end());
                    //check if the triplet is already in result
                    if (find(result.begin(), result.end(), triplet) == result.end()) {
                        result.push_back(triplet);
                    }
                    
                }
                numCount[num2]++; // restore count for second number
            }
            numCount[num]++; // restore count for first number
        }
        return result;

    }
};