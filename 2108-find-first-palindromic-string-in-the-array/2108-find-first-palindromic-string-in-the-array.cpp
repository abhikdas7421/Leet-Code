class Solution {
public:
    bool isPalindrome(string &str) {
        int i = 0;
        int j = str.length()-1;
        
        while(i < j) {
            if(str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        
        for(string str : words) {
            
            if(isPalindrome(str)) {
                
                return str;
            }
        }
        
        return "";
    }
};