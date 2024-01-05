class Solution {
public:
    int bs(vector<int> &nums, int target) {
        int s = 0, e = nums.size()-1;
        
        int index = -1;
        
        while(s <= e) {
            int m = s + (e-s)/2;
            
            if(nums[m] >= target) {
                index = m;
                e = m-1;
            }
            else if(nums[m] < target) {
                s = m+1;
            }
        }
        
        return index;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            }
            else {
                int index = bs(ans, nums[i]);
                ans[index] = nums[i];
            }
        }
        
        return ans.size();
        
    }
};