class Solution {
public:
    // Approach 2:- (2 pass) | T.C:- O(n+n) | S.C:- O(1)
    /*int maxFrequencyElements(vector<int>& nums) {
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
    }*/
    
    // Appraoch 3:- (1 pass) | T.C:- O(n) | S.C:- O(1)
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101);
        
        int maxFreq = 0;
        int total = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            
            if(maxFreq < freq[nums[i]]) {
                maxFreq = freq[nums[i]];
                total = maxFreq;
            }
            else if(maxFreq == freq[nums[i]]) {
                total += maxFreq;
            }
        }
        
        return total;
    }
};