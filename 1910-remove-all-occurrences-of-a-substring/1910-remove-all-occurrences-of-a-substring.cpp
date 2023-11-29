class Solution
{
    public:
        void removeOccRE(string &s, string &part) {
            auto pos = s.find(part);
            if(pos == string::npos) {
                return;
            }
            
            string leftPart = s.substr(0, pos);
            string rightPart = s.substr(pos+part.size());
            s = leftPart + rightPart;
            
            removeOccRE(s, part);
            
        }
    
        string removeOccurrences(string s, string part) {
            removeOccRE(s, part);
            
            return s;
        }
};