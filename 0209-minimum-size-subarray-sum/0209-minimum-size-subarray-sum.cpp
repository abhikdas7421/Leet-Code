class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        
        int sum = 0;
        int minLen = n+1;
        
        while(j < n) {
            sum += nums[j];
            
            while(sum >= target) {
                int currLen = j-i+1;
                minLen = min(minLen, currLen);
                
                sum -= nums[i];
                i++;
            }
            
            j++;
        }
        
        return (minLen == n+1) ? 0 : minLen;
        
    }
};