class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> hash(26, 0);
        
        int maxLen = 0;
        
        int i = 0;
        int j = 0;
        
        while(j < n) {
            hash[s[j]-'a']++;
            
            while(i < j && hash[s[j]-'a'] > 2) {
                hash[s[i]-'a']--;
                i++;
            }
            
            maxLen = max(j-i+1, maxLen);
            j++;
        }
        
        return maxLen;
    }
};