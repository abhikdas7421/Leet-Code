class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) { // T.C -> O(n) || S.C -> O(1)
        int duplicate, missing;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[abs(nums[i])-1] < 0) {
                duplicate = abs(nums[i]);
            }
            else{
                nums[abs(nums[i])-1] *= -1;
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                missing = i+1;
            }
        }
        
        return {duplicate, missing};
    }
};