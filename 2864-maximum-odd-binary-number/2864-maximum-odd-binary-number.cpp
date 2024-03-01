class Solution {
public:
    // Approach 1
    /*string maximumOddBinaryNumber(string s) {
        int n = s.length();
        
        string result = string(n, '0');
        
        int i = 0;
        for(char &ch : s) {
            if(ch == '1') {
                if(result[n-1] == '1') {
                    result[i] = '1';
                    i++;
                }
                else {
                    result[n-1] = '1';
                }
            }
        }
        
        return result;
    }*/
    
    // Approach 2
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        
        string result = string(n, '0');
        
        int count_1 = count(s.begin(), s.end(), '1');
        result[n-1] = '1';
        
        for(int i = 0; i < count_1-1; i++) {
            result[i] = '1';
        }
        
        return result;
        
    }
};