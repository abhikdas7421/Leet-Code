class Solution {
public:
    // Approach 1:- T.C:- O(nlogn) + O(n) | S.C:- O(n)
    /*vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        int i = 0;
        while(i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            int j = i+1;
            while(j < n && end >= intervals[j][0]) {
                end = max(end, intervals[j][1]);
                j++;
            }
            
            ans.push_back({start, end});
            i = j;
            
        }
        return ans;
        
    }*/
    
    // Appraoch 2:-
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
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
    }
    
};