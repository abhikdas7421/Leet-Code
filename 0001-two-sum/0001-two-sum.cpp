class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            int x = target-nums[i];
            
            if(mp.find(x) != mp.end()) {
                ans.push_back(mp[x]);
                ans.push_back(i);
                break;
            }
            
            mp[nums[i]] = i;
        }
        
        return ans;
    }
};