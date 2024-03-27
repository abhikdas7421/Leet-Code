class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if(p.size() > s.size()) return ans;
        
        vector<int> hash(26, 0);
        for(int i = 0; i < p.size(); i++) {
            int idx = p[i]-'a';
            hash[idx]++;
        }
        
        vector<int> currHash(26, 0);
        for(int i = 0; i < p.size(); i++) {
            int idx = s[i]-'a';
            currHash[idx]++;
        }
        
        if(hash == currHash) ans.push_back(0);
        
        int i = 0;
        int j = p.size();
        
        while(j < s.size()) {
            int idx1 = s[i]-'a';
            currHash[idx1]--;
            
            int idx2 = s[j]-'a';
            currHash[idx2]++;
            
            i++;
            j++;
            
            if(hash == currHash) ans.push_back(i);
        }
        
        return ans;
    }
};