class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size()-1;
        
        while(j <= n) {
            if(nums[i] != 0) {
                if(j <= i) {
                    j++;
                }
                i++;
            }
            else if(nums[j] == 0) {
                j++;
            }
            else{
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        
    }
};