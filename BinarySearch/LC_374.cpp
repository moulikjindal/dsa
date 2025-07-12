/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2; // To prevent overflow
            
            int result = guess(mid);
            if (result == 0) {
                return mid; // Found the number
            } else if (result < 0) {
                right = mid - 1; // The picked number is lower
            } else {
                left = mid + 1; // The picked number is higher
            }
        }
        return -1; // This line should never be reached if the input is valid
    }
};