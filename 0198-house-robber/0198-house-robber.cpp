class Solution {
public:
    int solve(vector<int> &nums, int i, vector<int> &dp) {
        // base case
        if(i >= nums.size()) {
            return 0;
        }
        
        if(dp[i] != -1) {
            return dp[i];
        }
        
        // not pick
        int np = solve(nums, i+1, dp);
        
        // pick
        int p = nums[i] + solve(nums, i+2, dp);
        
        dp[i] = max(np, p);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};