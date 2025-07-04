class Solution {
public:
    int characterReplacement(string s, int k) {
        int count =0;
        //so you can replace at most k characters with any other uppercase letter
        vector<int> freq(26, 0);
        // Use a sliding window approach to find the longest substring
        // that can be formed by replacing at most k characters.
        // freq[i] will store the frequency of character 'A' + i in the current window.
        // max_freq will keep track of the frequency of the most common character in the current window
        // If the current window size minus the most frequent character's count is greater than k,
        // we need to shrink the window from the left.
        // The length of the longest substring will be the maximum size of the window that satisfies the condition.
        int left = 0, max_freq = 0;
        for (int right = 0; right < s.size(); ++right) {
            freq[s[right] - 'A']++;
            max_freq = max(max_freq, freq[s[right] - 'A']);
            
            // If the current window size minus the most frequent character's count is greater than k,
            // we need to shrink the window from the left.
            if (right - left + 1 - max_freq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            
            count = max(count, right - left + 1);
        }
        return count;
    }
};
