class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n == 0) return dp[0] = 0;
        if(n == 1) return dp[1] = 1;
        if(n == 2) return dp[2] = 1;
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int x = solve(n-1, dp)+solve(n-2, dp)+solve(n-3, dp);
        return dp[n] = x;
    }
    
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};