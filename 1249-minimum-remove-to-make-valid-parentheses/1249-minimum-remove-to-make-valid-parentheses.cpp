class Solution {
public:
    // Approach:- 1 | T.C:- O(n) | S.C:- O(n)
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        stack<int> st;
        unordered_set<int> remove_idx;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(st.empty()) {
                    remove_idx.insert(i);
                }
                else {
                    st.pop();
                }
            }
        }
        
        while(!st.empty()) {
            remove_idx.insert(st.top());
            st.pop();
        }
        
        string result = "";
        
        for(int i = 0; i < n; i++) {
            if(remove_idx.find(i) == remove_idx.end()) {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
    
    /*string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '(') {
                st.push(i);
                i++;
            }
            else if(s[i] == ')') {
                
                if(!st.empty()) {
                    st.pop();
                    i++;
                }
                else {
                    s.erase(i, 1);
                }
            }
            else {
                i++;
            }
        }
        
        while(!st.empty()) {
            int idx = st.top();
            st.pop();
            s.erase(idx, 1);
        }
        
        return s;
        
    }*/
};