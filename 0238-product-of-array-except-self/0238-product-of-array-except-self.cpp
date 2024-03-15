class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        int product = 1;
        int count_zeros = 0;
        
        for(int &num : nums){
            if(num == 0){
                count_zeros++;
            }
            else{
                product *= num;
            }
        }
        
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++){
            
            if(count_zeros == 0){
                ans[i] = product/nums[i];
            }
            else if(count_zeros == 1 && nums[i] == 0){
                ans[i] = product;
            }
        }
        
        return ans;
        
        
    }
};