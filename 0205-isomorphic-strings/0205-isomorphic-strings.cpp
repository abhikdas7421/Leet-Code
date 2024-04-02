class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> hash(256, 0);
        vector<bool> isChar(256, false);
        
        for(int i = 0; i < s.size(); i++) {
            
            if(!isChar[t[i]]) {
                hash[s[i]] = t[i];
                isChar[t[i]] = true;
            }
        }
        
        for(int i = 0; i < t.size(); i++) {
            if(hash[s[i]] != t[i]) {
                return false;
            }
        }
        
        return true;
        
    }
};