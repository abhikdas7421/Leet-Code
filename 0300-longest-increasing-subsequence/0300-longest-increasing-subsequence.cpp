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
        
        if(nums.size() == 1) return 1;
        
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for(auto ele : nums) {
            if(ele > ans.back()) {
                ans.push_back(ele);
            }
            else {
                int index = bs(ans, ele);
                ans[index] = ele;
            }
        }
        
        return ans.size();
        
    }
};