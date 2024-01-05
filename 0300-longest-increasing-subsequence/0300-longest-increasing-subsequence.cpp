class Solution {
public:
    
    int solve(vector<int> &nums, int curr, int prev) {
        if(curr >= nums.size()) {
            return 0;
        }
        
        // pick
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            take = 1+solve(nums, curr+1, curr);
        }
        
        // not pick
        int notTake = solve(nums, curr+1, prev);
        
        return max(take, notTake);
    }
    
    int solveMem(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp) {
        if(curr >= nums.size()) {
            return 0;
        }
        
        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }
        
        // pick
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            take = 1+solveMem(nums, curr+1, curr, dp);
        }
        
        // not pick
        int notTake = solveMem(nums, curr+1, prev, dp);
        
        dp[curr][prev+1] = max(take, notTake);
        return dp[curr][prev+1];
        
    }
   
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solveMem(nums, 0, -1, dp);
    }
};