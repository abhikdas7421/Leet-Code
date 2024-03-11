class Solution {
public:
    string customSortString(string order, string s) {
        vector<char> freq(26,0);
        
        for(char &ch : s) {
            freq[ch-'a']++;
        }
        
        string ans = "";
        for(char &ch : order) {
            while(freq[ch-'a'] > 0) {
                ans.push_back(ch);
                freq[ch-'a']--;
            }
        }
        
        for(int i = 0; i < freq.size(); i++) {
            
            while(freq[i] > 0) {
                char ch = 'a'+i;
                ans.push_back(ch);
                freq[i]--;
            }
        }
        
        return ans;
    }
};