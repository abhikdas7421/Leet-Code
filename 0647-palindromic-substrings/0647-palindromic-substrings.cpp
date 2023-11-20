class Solution {
public:
    int expandAlongIndex(string s, int i, int j) {
        int count = 0;

        
        while((i >= 0) && (j <= s.size()-1) && (s[i] == s[j])) {
            count++;
            i--;
            j++;
        }
        
        return count;
    }
    
    int countSubstrings(string s) {
        
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            
            int oddCount = expandAlongIndex(s, i, i);
            int evenCount = expandAlongIndex(s, i, i+1);
            
            count += (oddCount + evenCount);
        }
        
        return count;
        
    }
};