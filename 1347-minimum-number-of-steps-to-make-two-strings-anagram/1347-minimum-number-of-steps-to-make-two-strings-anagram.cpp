class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> sFreq;
        unordered_map<char, int> tFreq;
        
        for(auto ch : s) {
            sFreq[ch]++;
        }
        
        for(auto ch : t) {
            tFreq[ch]++;
        }
        
        int count = 0;
        for(auto ch : s) {
            int sEleCount = sFreq[ch];
            int tEleCount = tFreq[ch];

            if (sEleCount > tEleCount)
            {
                count += sEleCount - tEleCount;
                sFreq[ch] = 0;
            }
        }
        
        return count;
        
    }
};