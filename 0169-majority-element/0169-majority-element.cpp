class Solution {
public:
    // Approach 1:- Using Map | T.C -> O(n) | S.C-> O(n)
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto num : nums) {
            mp[num]++;
        }
        
        int ans = -1;
        for(auto it : mp) {
            if(it.second > nums.size()/2) {
                ans = it.first;
                break;
            }
        }
        
        return ans;
    }
};