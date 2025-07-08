class Solution {
public:
    bool isalnum(char c) {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }
    bool isPalindrome(string s) {
        // string filtered = "";
        // for (char c : s) {
        //     if (isalnum(c)) {
        //         filtered += tolower(c);
        //     }
        // }
        // //initialize the two pointers
        // if (filtered.empty()) return true; // Edge case for empty string
        // int left = 0, right = filtered.size() - 1;
        // while (left < right) {
        //     if (filtered[left] != filtered[right]) {
        //         return false; // Mismatch found
        //     }
        //     left++;
        //     right--;
        // }
        //it takes time to filter the string, so we can do it in one pass
        int left = 0, right = s.size() - 1;
        while (left < right) {
            // Move left pointer to the next alphanumeric character
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            // Move right pointer to the previous alphanumeric character
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            // Compare characters in a case-insensitive manner
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // Mismatch found
            }
            left++;
            right--;
        }
        return true; // No mismatches found, it's a palindrome
    }
};