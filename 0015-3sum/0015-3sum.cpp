class Solution {
public:
    void twoSum(vector<int>& nums, int target, int i, int j, vector<vector<int>>& ans) {
        while(i < j) {
            if(nums[i]+nums[j] == target) {
                
                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;
                
                ans.push_back({-target, nums[i], nums[j]});
                
                i++;
                j--;
            }
            else if(nums[i]+nums[j] > target) {
                j--;
            }
            else if(nums[i]+nums[j] < target) {
                i++;
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        if(nums[0] > 0 || n < 3) {
            return {};
        }
        
        for(int i = 0; i < n-2; i++) {
            
            if(nums[i] > 0) break;
            
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            int n1 = nums[i];
            int target = -n1;
            
            twoSum(nums, target, i+1, n-1, ans);
        }
        
        return ans;
        
    }
};