class Solution {
public:
    int slidingWindowHelper(vector<int>& nums, int k) {
        int n = nums.size();
        int oddCount = 0;
        
        int i = 0;
        int j = 0;
        int result = 0;
        
        while(j < n) {
            if(nums[j]%2 != 0) oddCount++;
            
            while(i < j && oddCount > k) {
                if(nums[i]%2 != 0) oddCount--;
                i++;
            }
            
            if(oddCount <= k) {
                result += (j-i+1);
            }
            
            j++;
        }
        
        return result;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count1 = slidingWindowHelper(nums, k);
        int count2 = slidingWindowHelper(nums, k-1);
        
        int result = count1-count2;
        return result;
    }
};