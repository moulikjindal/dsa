class Solution {
public:
    int climbStairs(int n) {
        if (n<4) {
            return n;
        }
        int dp[n+1];
        dp[0] = 0; // Base case: 0 ways to climb 0 stairs
        dp[1] = 1; // Base case: 1 way to climb 1 stair
        dp[2] = 2; // Base case: 2 ways to climb 2 stairs (1+1, 2)
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2]; // Recurrence relation: ways to climb i stairs is the sum of ways to climb (i-1) and (i-2) stairs, because thik of it like this, if you are at stair i, you can either come from stair i-1 (1 step) or stair i-2 (2 steps)
        }
        return dp[n]; // Return the number of ways to climb n stairs
        
    
    }
};
