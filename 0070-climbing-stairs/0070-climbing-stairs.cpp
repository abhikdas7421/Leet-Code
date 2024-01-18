class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n == 0 || n == 1) {
            dp[n] = 1;
            return dp[n];
        }
        
        if(dp[n] != 0) {
            return dp[n];
        }
        
        int a = solve(n-1, dp);
        int b = solve(n-2, dp);
        
        dp[n] = a+b;
        return dp[n];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        solve(n, dp);
        return dp[n];
    }
};