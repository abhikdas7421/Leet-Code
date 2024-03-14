class Solution {
public:
    // Approach:- 1
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int result = 0;
        int currSum = 0;
        
        mp[0] = 1;
        
        for(int &num : nums) {
            currSum += num;
            
            if(mp.find(currSum-goal) != mp.end()) {
                result += mp[currSum-goal];
            }
            
            mp[currSum]++;
        }
        
        return result;
    }
};