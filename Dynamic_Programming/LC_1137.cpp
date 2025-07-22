class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 1;
        if (n == 0) return first;
        if (n == 1) return second;
        if (n == 2) return third;
        for (int i = 3; i <= n; ++i) {
            int next = first + second + third;
            first = second;
            second = third;
            third = next;
        }
        return third;
        
    }
};