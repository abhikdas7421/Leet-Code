class Solution {
public:
    // My Approach
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
    
    // Approach:- 1 | T.C:- O(n) | S.C:- O(n)
    /*string minRemoveToMakeValid(string s) {
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
    }*/
    
    // Approach:- 2 | T.C:- O(n) | S.C:- O(n)
    // Iterate left to right -> Eleminate extra close brackets
    // Iterate right to left -> Eleminate extra open brackets
    /*string minRemoveToMakeValid(string s) {
        int n = s.size();
        
        string result = "";
        
        // Iterte left to right
        int open = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open++;
                result.push_back(s[i]);
            }
            else if(s[i] == ')') {
                if(open > 0) {
                    open--;
                    result.push_back(s[i]);
                }
            }
            else {
                result.push_back(s[i]);
            }
        }
        
        string final_result = "";
        
        // Iterate right to left
        int close = 0;
        for(int i = result.size()-1; i >= 0; i--) {
            if(result[i] == ')') {
                close++;
                final_result.push_back(result[i]);
            }
            else if(result[i] == '(') {
                if(close > 0) {
                    close--;
                    final_result.push_back(result[i]);
                }
            }
            else {
                final_result.push_back(result[i]);
            }
        }
        
        reverse(final_result.begin(), final_result.end());
        return final_result;
    }*/
    
    // Approach:- 3
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        string temp = "";
        
        int open = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open++;
                temp.push_back(s[i]);
            }
            else if(s[i] == ')') {
                if(open > 0) {
                    open--;
                    temp.push_back(s[i]);
                }
            }
            else {
                temp.push_back(s[i]);
            }
        }
        
        string result = "";
        
        for(int i = temp.size()-1; i >= 0; i--) {
            if(temp[i] == '(' && open > 0) {
                open--;
            }
            else {
                result.push_back(temp[i]);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    
};