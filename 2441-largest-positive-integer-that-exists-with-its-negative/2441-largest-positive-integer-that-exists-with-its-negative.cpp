class Solution {
public:
    // Approach:- 1 | T.C:- O(n) | S.C:- O(n)
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        int ans = -1;
        
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            
            if(mp.find(-x) != mp.end()) {
                ans = max(ans, abs(x));
            }
        }
        
        return ans;
    }
};