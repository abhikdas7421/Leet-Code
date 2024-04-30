class Solution {
public:
    void twoSum(vector<int>& nums, int si, int target, vector<vector<int>>& ans) {
        int n = nums.size();
        
        int i = si;
        int j = n-1;
        
        while(i < j) {
            if(nums[i] + nums[j] == target) {
                // handle duplicate
                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;
                
                ans.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            }
            else if(nums[i] + nums[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        if(nums[0] > 0) return ans;
        
        for(int i = 0; i < n-2; i++) {
            if(nums[i] > 0) break;
            
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            int n1 = nums[i];
            int target = -n1;
            
            twoSum(nums, i+1, target, ans);
        }
        
        return ans;
    }
};