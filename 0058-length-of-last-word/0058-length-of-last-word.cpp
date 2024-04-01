class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int wordLength = 0;
        
        for(int i = n-1; i >= 0; i--) {
            
            if(s[i] != ' ') {
                wordLength++;
            }
            else if(s[i] == ' ' && wordLength != 0){
                break;
            }
        }
        
        return wordLength;
    }
};