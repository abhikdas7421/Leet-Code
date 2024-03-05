class Solution {
public:
    int minimumLength(string s) {
        int low = 0;
        int high = s.length()-1;
        
        while(low < high) {
            if(s[low] == s[high]) {
                char ch = s[low];
                
                while(low < s.length() && ch == s[low]) {
                    low++;
                }
                
                while(high >= 0 && ch == s[high]) {
                    high--;
                }
            }
            else {
                break;
            }  
        }
        
        int len = (low > high) ? 0 : high-low+1;
        return len;
    }
};