class Solution {
public:
    void removeOccurrencesRE(string &s, string &part) {

        // base case
        if(s.find(part) == string::npos) {
            return;
        }

        // let's solve 1 case
        int pos = s.find(part);
        
        // part string has been located
        // remove it

        // string left_part = s.substr(0, pos);
        // string right_part = s.substr(pos+part.size(), s.size());
        // s = left_part + right_part;  
        
        s.erase(pos, part.size());
        

        // RR
        removeOccurrencesRE(s, part);  
    }

    string removeOccurrences(string s, string part) {
       removeOccurrencesRE(s, part);
       return s;
    }
};