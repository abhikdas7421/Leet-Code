class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        st.push(0);
        
        for(int i = nums.size()-1; i >= 0; i--) {
            int curr = nums[i];
            while(!st.empty() && st.top() > curr) {
                st.pop();
            }
            
            ans.push_back(st.top());
            st.push(curr);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> nextSmallerPrices = nextSmallerElement(prices);
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            ans[i] = prices[i] - nextSmallerPrices[i];
        }
        
        return ans;
    }
};