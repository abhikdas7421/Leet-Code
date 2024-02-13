class Solution {
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
    
public:
    string firstPalindrome(vector<string>& words) {
        
        for(string word : words) {
            
            if(isPalindrome(word))
                return word;
        }
        
        return "";
    }
};