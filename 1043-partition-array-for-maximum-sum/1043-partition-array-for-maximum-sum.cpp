class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<int> &dp) {
        if(i >= arr.size()) {
            return 0;
        }
        
        if(dp[i] != -1) {
            return dp[i];
        }
        
        int result = 0;
        int curr_max = -1;
        
        for(int j = i; j < arr.size() && j-i+1 <= k; j++) {
            curr_max = max(curr_max, arr[j]);
            
            
            result = max(result, (j-i+1) * curr_max + solve(j+1, arr, k, dp));
        }
        
        return dp[i] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, -1);
        return solve(0, arr, k, dp);
    }
};