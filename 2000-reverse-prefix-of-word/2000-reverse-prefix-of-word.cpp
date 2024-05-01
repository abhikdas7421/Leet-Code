class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int j = -1;
        
        for(int i = 0; i < n; i++) {
            if(word[i] == ch) {
                j = i;
                break;
            }
        }
        
        if(j != -1) {
            reverse(word.begin(), word.begin()+j+1);
        }
        
        return word;
    }
};