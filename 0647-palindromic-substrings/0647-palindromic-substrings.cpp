class Solution {
public:
    int expandAlongIndex(string &s, int i, int j) {
        int ans = 0;
        
        while(i >= 0 && j < s.length()) {
            
            if(s[i] != s[j]) {
                break;
            }
            ans++;
            i--;
            j++;
        }
        
        return ans;
        
    }
    int countSubstrings(string s) {
        
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            int odd = expandAlongIndex(s, i, i);
            
            int even = expandAlongIndex(s, i, i+1);
            
            ans += odd+even;
        }
        
        return ans;
    }
};