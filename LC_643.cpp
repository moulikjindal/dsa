
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<double> dup; 
        for (auto num : nums){
            dup.push_back(double(double(num)/k));
        }
        double maxSum = 0;
        double currentSum = 0;
        //window size k
        for (int i = 0; i < k; i++) {
            currentSum += dup[i];
        }
        //
        maxSum = currentSum;
        //moving the window
        for (int i = k; i < dup.size(); i++) {
            currentSum += dup[i] - dup[i - k];
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};