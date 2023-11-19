class Solution {
public:
    void removeOccurrencesRE(string &s, string &part) {
        
        if(s.find(part) == string::npos) {
            return;
        }
        
        int pos = s.find(part);
        s.erase(pos, part.length());
        
        removeOccurrencesRE(s, part);
    }
    string removeOccurrences(string s, string part) {
        removeOccurrencesRE(s, part);
        
        return s;
        
    }
};