class Solution {
public:
    string reorganizeString(string s) {
        int sz = s.size();
        int len = (sz+1)/2;
        vector<int> mp(26, 0);
        
        for(int i = 0; i < sz; i++) {
            mp[s[i]-'a']++;
            
            if(mp[s[i]-'a'] > len) {
                return "";
            }
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
        
        // if(occNo != 0) {
        //     return "";
        // }
        
        mp[mostOccCh - 'a'] = occNo;
        
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