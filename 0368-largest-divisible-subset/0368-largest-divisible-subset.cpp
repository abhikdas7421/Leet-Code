class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> dp(n, 1);
        vector<int> prevIndex(n, -1);
        
        int maxLen = 1;
        int index = 0;

        for(int i = 1; i < n; i++) {
            
            for(int j = 0; j < i; j++) {
                
                if(nums[i] % nums[j] == 0) {
                    
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j]+1;
                        prevIndex[i] = j;
                    }
                    
                    
                    if(dp[i] > maxLen) {
                        maxLen = dp[i];
                        index = i;
                    }
                }
            }
        }
        
        vector<int> result;
        while(index != -1) {
            result.push_back(nums[index]);
            index = prevIndex[index];
        }
        
        return result;
    }
};