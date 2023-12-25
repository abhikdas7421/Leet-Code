class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>> &ans) {
        // base case
        if(i >= nums.size()) { 
            ans.push_back(nums);
            return;
        }
        
        unordered_map<int, bool> visited;
        
        for(int j = i; j < nums.size(); j++) {
            
            if(visited.find(nums[j]) != visited.end()) {
                
                continue;
            }
            
            visited[nums[j]] = true;
            
            swap(nums[i], nums[j]);
            solve(nums, i+1, ans);
            swap(nums[i], nums[j]);  
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        solve(nums, 0, ans);
        
        // set<vector<int>> temp;
        // for(auto it : ans) {
        //     // T.C -> O(logn)
        //     temp.insert(it);
        // }
        // ans.clear();
        // for(auto it : temp) {
        //     ans.push_back(it);
        // }
        
        return ans;
    }
};