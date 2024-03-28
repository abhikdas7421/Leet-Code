class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0, ans = 0;
        unordered_map<int, int> freq;
        
        while(j < n) {
            freq[nums[j]]++;
            
            while(freq[nums[j]] > k) {
                freq[nums[i]]--;
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
        }
        
        return ans;
        
        
    }
};