class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for (char c : s1) {
            freq[c - 'a']++;
        }
        // Sliding window
        int left = 0, right = 0, count = s1.size();
        while (right < s2.size()) {
            // If the current character is part of s1, decrease the count
            // Otherwise, it means we have a character that is not in s1
            if (freq[s2[right] - 'a'] > 0) {
                count--;
            }
            // Decrease the frequency of the current character
            // If the character is not in s1, it will not affect the count

            freq[s2[right] - 'a']--;

            // Move the right pointer to expand the window
            right++;

            // If the count is zero, it means we have a valid permutation
            if (count == 0) {
                return true;
            }

            //
            if (right - left == s1.size()) {
                // If the window size is equal to s1 size, we need to move the left pointer
                if (freq[s2[left] - 'a'] >= 0) {
                    count++;
                }
                freq[s2[left] - 'a']++;
                left++;
            }
        }
        return false;
    }
};