class Solution {
public:
    // Approach:- 1 | T.C:- O(n) | S.C:- O(1)
    /*int lengthOfLastWord(string s) {
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
    }*/
    
    // Approach:- 2 (Using stl function)
    int lengthOfLastWord(string s) {
        
        int idx = s.find_last_not_of(' ') + 1;
        s.erase(idx);
        
        int last_space_idx = s.find_last_of(' ');
        
        return last_space_idx == string::npos ? s.size() : s.size()-last_space_idx-1;
    }
};