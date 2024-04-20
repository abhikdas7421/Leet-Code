class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        
        int windowSum = 0;
        int minLen = INT_MAX;
        
        while(j < n) {
            windowSum += nums[j];
            
            while(i <= j && windowSum >= target) {
                minLen = min(minLen, j-i+1);
                
                windowSum -= nums[i];
                i++;
            }
            
            j++;
        }
        
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};