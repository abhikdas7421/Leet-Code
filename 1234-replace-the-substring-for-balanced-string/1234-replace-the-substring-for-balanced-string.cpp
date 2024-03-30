class Solution {
public:
    int slidingWindowHelper(string &s, unordered_map<char, int> mp) {
        int n = s.size();
        unordered_map<char, int> mp2 = mp;
        int mSize = mp2.size();
        
        int i = 0;
        int j = 0;
        int result = n;
        
        while(j < n) {
            if(mp2.find(s[j]) != mp2.end()) {
                
                mp2[s[j]]--;
                
                if(mp2[s[j]] == 0) {
                    mSize--;
                }
            }
            
            while(i <= j && mSize == 0) {
                
                result = min(j-i+1, result);
                
                if(mp.find(s[i]) != mp.end()) {
                    mp2[s[i]]++;
                    
                    if(mp2[s[i]] > 0) {
                        mSize++;
                    }
                }
                i++;
            }
            
            j++;
        }
        
        return result;
    }
    
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        
        for(char &ch : s) {
            mp[ch]++;
        }
        
        int k = n/4;
        string str = "QWER";
        for(auto &ch : str) {
            if(mp[ch] <= k) {
                mp.erase(ch);
            }
            else {
                mp[ch] -= k;
            }
        }
        
        if(mp.size() == 0) return 0;
        
        int result = slidingWindowHelper(s, mp);
        return result;
    }
};