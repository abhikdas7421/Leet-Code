class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> hash(256, 0);
        vector<bool> isCharMap(256, false);
        
        for(int i = 0; i < s.size(); i++) {
            
            if(!isCharMap[t[i]]) {
                hash[s[i]] = t[i];
                isCharMap[t[i]] = true;
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