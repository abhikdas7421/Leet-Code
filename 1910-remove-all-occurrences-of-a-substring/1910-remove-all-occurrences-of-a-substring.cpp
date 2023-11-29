class Solution
{
    public:
        void removeOccRE(string &s, string &part) {
            auto pos = s.find(part);
            if(pos == string::npos) {
                return;
            }
            
            s.erase(pos, part.size());
            
            removeOccRE(s, part);
            
        }
    
        string removeOccurrences(string s, string part) {
            removeOccRE(s, part);
            
            return s;
        }
};