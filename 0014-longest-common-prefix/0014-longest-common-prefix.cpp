class Solution {
public:
    string findPrefix(string str1, string str2) {
        int i = 0;
        while(i < str1.size() && i < str2.size()) {
          if(str1[i] != str2[i])  {
              break;
          }
            i++;
        }
        
        if(i == 0) {
            return "";
        }
        
        string s = str1.substr(0, i);
        return s;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) {
            return strs[0];
        }
        
        string str1 = strs[0];
        
        for(int i = 1; i < strs.size(); i++) {
            string str2 = strs[i];
            str1 = findPrefix(str1, str2);
            
            if(str1.size() == 0) {
                return "";
            }
        }
        
        return str1;
    }
};