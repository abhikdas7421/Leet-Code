class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& v) {
        int n = v.size();
        
        stack<int> st;
        st.push(n);
        
        vector<int> ans;
        
        for(int i = n-1; i >= 0; i--) {
            int curr = v[i];
            
            while(!st.empty() && st.top() != n && v[st.top()] >= curr) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int>& v) {
        int n = v.size();
        
        stack<int> st;
        st.push(-1);
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            int curr = v[i];
            
            while(!st.empty() && st.top() != -1 && v[st.top()] >= curr) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmallerElement(heights);
        vector<int> prev = prevSmallerElement(heights);
        
        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++) {
            int width = next[i]-prev[i]-1;
            int height = heights[i];
            int currArea = width * height;
            
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
};