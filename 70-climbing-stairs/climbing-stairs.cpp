class Solution {
public:
    // this is memoized solution // n = 5, and so i make the array of size 6 cuz
    // 0 is also there
    int calculateNumberOfDistictWays(int n, vector<int>& dp) {
        if (n == 1 || n == 0) {
            return 1;
        }

        if(dp[n] != -1) return dp[n];

        return dp[n] = calculateNumberOfDistictWays(n - 1, dp) +
               calculateNumberOfDistictWays(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return calculateNumberOfDistictWays(n, dp);
    }
};