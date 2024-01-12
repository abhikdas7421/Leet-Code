class Solution {
public:
    int numberOfVowels(string s) {
        
        int count = 0;
        for(auto ch:s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                count++;
                
            }
        }
        
        return count;
        
    }
    
    bool halvesAreAlike(string s) {
        
        int size = s.size();
        
        string a = s.substr(0, size/2);
        string b = s.substr(size/2);
        
        int aNum = numberOfVowels(a);
        int bNum = numberOfVowels(b);
        
        return aNum == bNum;
        
    }
};