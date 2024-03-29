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
            
            while(i < j && maxCount >= k) {
                result += (n-j);
                
                if(nums[i] == maxi) {
                    maxCount--;
                }
                i++;
            }
            
            if(i == j && maxCount == k) {
              result++;
            }
            
            j++;
        }
        
        return result;
    }
};

// [28,5,58,91,24,91,53,9,48,85,16,70,91,91,47,91,61,4,54,61,49]
// 1