class Solution {
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
    
public:
    // Convert char matrix to int matrix
    vector<vector<int>> ctoi(vector<vector<char>> &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> v;
        
        for(int i = 0; i < rows; i++) {
            vector<int> t;
            for(int j = 0; j < cols; j++) {
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        
        return v;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> v = ctoi(matrix);
        
        int area = largestRectangleArea(v[0]);
        
        for(int i = 1; i < n; i++) {
            
            for(int j = 0; j < m; j++) {
                
                if(v[i][j]) {
                    v[i][j] += v[i-1][j];
                }
                else {
                    v[i][j] = 0;
                }
            }
            
            area = max(area, largestRectangleArea(v[i]));
        }
        
        return area;
    }
};



















