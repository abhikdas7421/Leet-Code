class Solution {
public:
    // Approach 1:-
    /*string customSortString(string order, string s) {
        vector<char> freq(26,0);
        
        for(char &ch : s) {
            freq[ch-'a']++;
        }
        
        string ans = "";
        for(char &ch : order) {
            while(freq[ch-'a'] > 0) {
                ans.push_back(ch);
                freq[ch-'a']--;
            }
        }
        
        for(int i = 0; i < freq.size(); i++) {
            while(freq[i] > 0) {
                char ch = 'a'+i;
                ans.push_back(ch);
                freq[i]--;
            }
        }
        
        return ans;
    }*/
    
    // Approach 2:-
    string customSortString(string order, string s) {
        vector<int> index(26, -1);
        
        for(int i = 0; i < order.size(); i++) {
            char ch = order[i];
            index[ch-'a'] = i;
        }
        
        auto myCmp = [&index] (char &ch1, char &ch2) {
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(s.begin(), s.end(), myCmp);
        return s;
    }
};