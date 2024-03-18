class Solution {
public:
    // Approach 1:- Sort -> starting point
    /*int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        
        int arrow = 0;
        vector<int> prev = points[0];
        
        int i = 1;
        while(i < n) {
            
            if(prev[1] < points[i][0]) { // no overlap
                prev = points[i];
                i++;
                arrow++;
            }
            else { // overlap
                prev[0] = max(prev[0], points[i][0]);
                prev[1] = min(prev[1], points[i][1]);
                i++;
            }
        }
        
        return arrow+1;
    }*/
    
    // Approach 2:- Sort -> ending point
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        
        int arrow = 1;
        int prevEnd = points[0][1];
        
        
        for(int i = 1; i < n; i++) {
            if(points[i][0] > prevEnd) {
                arrow++;
                prevEnd = points[i][1];
            }
        }
        
        return arrow;
    }
};