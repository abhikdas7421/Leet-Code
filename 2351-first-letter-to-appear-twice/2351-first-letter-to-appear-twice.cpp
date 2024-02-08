class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> freq(26, 0);
        
        char ans;
        for(auto ch : s) {
            freq[ch-'a']++;
            
            if(freq[ch-'a'] == 2) {
                ans = ch;
                break;
            }
        }
        
        return ans;
    }
};