class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mp(26, 0);
        
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]-'a']++;
        }
        
        int occNo = INT_MIN;
        char mostOccCh;
        
        for(int i = 0; i < 26; i++) {
            if(mp[i] > occNo) {
                occNo = mp[i];
                mostOccCh = 'a'+i;
            }
        }
        
        int j = 0;
        while(occNo > 0 && j < s.size()) {
            s[j] = mostOccCh;
            occNo--;
            j += 2;
        }
        
        if(occNo != 0) {
            return "";
        }
        
        mp[mostOccCh - 'a'] = 0;
        
        for(int i = 0; i < 26; i++) {
            
            while(mp[i]) {
                if(j >= s.size()) {
                    j = 1;
                }
                s[j] = i+'a';
                mp[i]--;
                j += 2;  
            }
        }
        
        return s;
        
    }
};