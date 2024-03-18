class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
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
            else {
                prev[0] = max(prev[0], points[i][0]);
                prev[1] = min(prev[1], points[i][1]);
                i++;
            }
        }
        
        return arrow+1;
        
       
    }
};