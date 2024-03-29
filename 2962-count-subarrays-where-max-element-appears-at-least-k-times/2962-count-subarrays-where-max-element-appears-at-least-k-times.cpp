class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        int maxi = *max_element(nums.begin(), nums.end());
        int maxCount = 0;
        
        int i = 0;
        int j = 0;
        long long result = 0;
        
        while(j < n) {
            if(nums[j] == maxi) maxCount++;
            
            while(maxCount >= k) {
                result += (n-j);
                
                if(nums[i] == maxi) {
                    maxCount--;
                }
                i++;
            }
            j++;
        }
        
        return result;
    }
};