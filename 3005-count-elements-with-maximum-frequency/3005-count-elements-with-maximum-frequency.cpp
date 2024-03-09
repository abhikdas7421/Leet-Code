class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101);
        
        int maxFreq = 0;
        int maxFreqCount = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            
            if(maxFreq < freq[nums[i]]) {
                maxFreq = freq[nums[i]];
                maxFreqCount = 1;
            }
            else if(maxFreq == freq[nums[i]]) {
                maxFreqCount++;
            }
        }
        
        int result = maxFreq*maxFreqCount;
        return result;
    }
};