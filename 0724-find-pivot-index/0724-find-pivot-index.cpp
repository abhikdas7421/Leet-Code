class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);
        
        int i = 0;
        while(i < n) {
            if(i != 0) {
                left += nums[i-1];
            }
            
            right -= nums[i];
            
            if(left == right) {
                return i;
            }
            i++;
        }
        
        return -1;
    }
};