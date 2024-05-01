class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(s.find(nums[i]-1) == s.end()) {
                int x = nums[i];
                int count = 1;
                
                while(s.find(x+1) != s.end()) {
                    x++;
                    count++;
                }
                
                maxLen = max(maxLen, count);
            }
        }
        
        return maxLen;
        
    }
};