class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (s.find(nums[i]) != s.end()) {
                return true;    
            }
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
            
    }
};
