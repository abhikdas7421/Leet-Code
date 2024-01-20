class Solution {
public:
    vector<int> nextSmallerEle(vector<int> &v) {
        stack<int> st;
        st.push(v.size());
        
        vector<int> ans;
        for(int i = v.size()-1; i >= 0; i--) {
            
            while(st.top() < v.size() && v[st.top()] >= v[i]) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> prevSmallerEle(vector<int> &v) {
        stack<int> st;
        st.push(-1);
        
        vector<int> ans;
        for(int i = 0; i < v.size(); i++) {
            
            while(st.top() >= 0 && v[st.top()] >= v[i]) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        
        return ans;
        
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int maxArea = 0;
        
        vector<int> nextSmallerIndex = nextSmallerEle(heights);
        vector<int> prevSmallerIndex = prevSmallerEle(heights);
        
        for(int i = 0; i < n; i++) {
            int next = nextSmallerIndex[i];
            int prev = prevSmallerIndex[i];
            
            int currWidth = next - prev - 1;
            int currArea = heights[i] * currWidth;
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
        
    }
};