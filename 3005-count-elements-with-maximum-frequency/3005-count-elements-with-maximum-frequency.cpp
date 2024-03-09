class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101);
        
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        int maxFreq = 0;
        int maxFreqCount = 0;
        
        for(int i = 0; i < freq.size(); i++) {
            if(maxFreq < freq[i]) {
                maxFreq = freq[i];
                maxFreqCount = 1;
            }
            else if(maxFreq == freq[i]) {
                maxFreqCount++;
            }
        }
        
        int result = maxFreq*maxFreqCount;
        return result;
    }
};