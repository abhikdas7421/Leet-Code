class Solution
{
    public:
        
        // Approach :- 1 (best approach-iterative approach)
        /* string removeDuplicates(string s)
        {
            string ans = "";
            int i = 0;

            while (i < s.length())
            {
                int lastIndex = ans.length() - 1;

                if (lastIndex >= 0 && s[i] == ans[lastIndex])
                {
                    ans.pop_back();
                }
                else
                {
                    ans.push_back(s[i]);
                }
                i++;
            }

            return ans;
        }
        */
        
        // Approach :- 2 (Using stack)
        string removeDuplicates(string s) {
            stack<char> st;
            for(auto ch : s) {
                if(!st.empty() && ch == st.top()) {
                    st.pop();
                }
                else {
                   st.push(ch);
                }
            }
            
            
            string ans;
            while(!st.empty()) {
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
            
        }
};