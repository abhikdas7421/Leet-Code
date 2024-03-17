class Solution {
public:
    // Approach 1:- T.C:- O(nlogn)
    /*vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end()); // O(nlogn)
        
        int n = intervals.size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            
            if(ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        
        return ans;
    }*/
    
    // Approach 2:- T.C:- O(n)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        vector<vector<int>> ans;
        
        int i = 0;
        while(i < n) {
            if(intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]) {
                break;
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        
        ans.push_back(newInterval);
        
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};
    
    
    
    
    
    
    
    