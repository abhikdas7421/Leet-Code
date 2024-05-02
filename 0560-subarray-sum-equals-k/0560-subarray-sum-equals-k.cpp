class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int cumSum = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            cumSum += nums[i];
            
            if(mp.find(cumSum-k) != mp.end()) {
                ans += mp[cumSum-k];
            }
            
            mp[cumSum]++;
        }
        
        return ans;
    }
};