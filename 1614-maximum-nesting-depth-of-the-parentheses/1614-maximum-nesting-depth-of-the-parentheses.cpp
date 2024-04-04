class Solution {
public:
    // Approach:- 1 | T.C:- O(n) | S.C:- O(n)
    /*int maxDepth(string s) {
        int len = s.size();
        stack<int> st;
        int result = 0;
        
        for(char &ch : s){
           
            if(ch == '('){
                st.push(ch);
                if(result < st.size()){
                    result = st.size();
                }
            }
            else if(ch == ')'){
                st.pop();
            }  
        }
        
        return result;
        
    }*/
    
    // Approach:- 2 | T.C:- O(n) | S.C:- O(1)
    int maxDepth(string s) {
        int len = s.size();
        int count = 0;
        int result = 0;
        
        for(char &ch : s){
           
            if(ch == '('){
                count++;
                result = max(result, count);
            }
            else if(ch == ')'){
                count--;
            }
        }
        
        return result;
        
    }
};