class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>> &ans) {
        // base case
        if(i >= nums.size()) {
            
            ans.push_back(nums);
            return;
        }
        
        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            solve(nums, i+1, ans);
            swap(nums[i], nums[j]);  
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        solve(nums, 0, ans);
        
        set<vector<int>> temp;
        for(auto it : ans) {
            temp.insert(it);
        }
        
        vector<vector<int>> finalAns;
        
        for(auto it : temp) {
            finalAns.push_back(it);
        }
        
        return finalAns;
    }
};