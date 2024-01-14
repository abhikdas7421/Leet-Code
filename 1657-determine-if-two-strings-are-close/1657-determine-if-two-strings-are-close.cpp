class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) {
            return false;
        }
        
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        for(auto ch : word1) {
            freq1[ch-'a']++;
        }
        for(auto ch : word2) {
            freq2[ch-'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
            
        }
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return freq1 == freq2;
    }
};