class Solution {
public:
    vector<int> nextSmallerIndex(vector<int> &arr) {
        stack<int> st;
        st.push(arr.size());
        
        vector<int> ans;
        for(int i = arr.size()-1; i >= 0; i--) {
            
            while(st.top() < arr.size() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            ans.push_back(st.top());
            st.push(i);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> prevSmallerIndex(vector<int> &arr) {
        stack<int> st;
        st.push(-1);
        
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            
            while(st.top() >= 0 && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int M = 1000000007;
        
        vector<int> next = nextSmallerIndex(arr);
        vector<int> prev = prevSmallerIndex(arr);
        long int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            long int left = (i-prev[i])%M;
            long int right = (next[i] - i)%M;
            
            // ans += ((left*right*arr[i]) % M);
            
            ans = (ans%M) + (left*right*(arr[i]%M))%M;
        }
        
        int finalAns = ans%M;
        return finalAns;
        
    }
};