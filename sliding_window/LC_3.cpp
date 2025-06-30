class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int n = s.size();
        int currsize = 0;
        for (int i = 0; i < n; ++i) {
            if (charIndexMap.find(s[i]) == charIndexMap.end()) { 
                currsize++;
            }
            else {
                currsize = charIndexMap[s[i]]+1;
            }
            maxLength = max(maxLength, i-currsize);
        }
        return maxLength;

    }
};
