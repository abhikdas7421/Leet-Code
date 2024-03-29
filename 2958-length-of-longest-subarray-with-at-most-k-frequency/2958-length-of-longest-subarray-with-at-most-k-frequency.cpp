class Solution {
public:
    // Approach:- 1 | T.C:- O(n) | S.C:- O(1)
    /*int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0, ans = 0;
        
        unordered_map<int, int> freq;
        
        while(j < n) {
            freq[nums[j]]++;
            
            while(i < j && freq[nums[j]] > k) {
                freq[nums[i]]--;
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
        }
        
        return ans;
    }*/
    
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int i = 0;
        int j = 0;
        int result = 0;
        
        int culprit = 0;
        
        while(j < n) {
            mp[nums[j]]++;
            
            if(mp[nums[j]] == k+1) {
                culprit++;
            }
            
            if(culprit > 0) {
                mp[nums[i]]--;
                if(mp[nums[i]] == k) {
                    culprit--;
                }
                i++;
            }
            
            if(culprit == 0) {
                result = max(result, j-i+1);
            }
            j++;
        }
        
        return result;
    }
};