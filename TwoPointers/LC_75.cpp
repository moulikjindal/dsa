class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zerolastindex = 0;
        int onefirstindex = 0;
        int twolastindex = nums.size() - 1;
        while (onefirstindex <= twolastindex) {
            if (nums[onefirstindex] == 0) {
                swap(nums[zerolastindex], nums[onefirstindex]);
                zerolastindex++;
                onefirstindex++;
            } else if (nums[onefirstindex] == 1) {
                onefirstindex++;
            } else {
                swap(nums[onefirstindex], nums[twolastindex]);
                twolastindex--;
            }
        }
    }
};