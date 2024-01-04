class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOperation = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        for(auto it:freq) {
            int ele = it.first;
            int eleCount = it.second;
            
            while(eleCount > 1) {
                if(eleCount == 3 || eleCount > 4) {
                    freq[ele] = freq[ele]-3;
                    eleCount -= 3;
                    ++minOperation;
                }
                else if(eleCount >= 2) {
                    freq[ele] = freq[ele]-2;
                    eleCount -= 2;
                    ++minOperation;
                }
            }
            
            if(eleCount == 1) {
                return -1;
            }
        }
        
        return minOperation;
    }
};