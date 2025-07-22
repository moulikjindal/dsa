class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        int first = cost[0], second = cost[1]; // first is cost[0], second is cost[1]
        for (int i = 2; i < n; ++i) { 
            int current = cost[i] + min(first, second); // 
            first = second;
            second = current;
        }
        return min(first, second);
    }
};


//the approach is simple
//// we can use two variables to keep track of the minimum cost to reach the last two steps
// and then update them as we iterate through the cost array
//we start from the third step and calculate the minimum cost to reach that step
// then you are left with the third step with the minimum cost to reach it 
// and one before it which will be the second step
//so we can continue this process until we reach the end of the array
//finally, we return the minimum of the last two steps
// Time Complexity: O(n) where n is the number of steps