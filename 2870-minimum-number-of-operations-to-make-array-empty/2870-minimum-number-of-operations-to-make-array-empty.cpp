class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        int minOperation = 0;
        for(auto it:freq) {
            int eleCount = it.second;
            if(eleCount== 1) return -1;
            
            minOperation += (eleCount/3);
            if(eleCount%3) {
                minOperation++;
            }
        }
        
        return minOperation;
    }
};