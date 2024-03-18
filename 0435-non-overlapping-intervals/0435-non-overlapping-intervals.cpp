class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        int count = 0;
        
        int i = 0, j = 1;
        
        while(j < n) {
            vector<int> currInterval = intervals[i];
            vector<int> nextInterval = intervals[j];
            
            int cs = currInterval[0];
            int ce = currInterval[1];
            
            int ns = nextInterval[0];
            int ne = nextInterval[1];
            
            if(ce <= ns) { // no overlapping
                i = j;
                j++;
            }
            else if(ce <= ne) { // overlapping
                j++;
                count++;
            }
            else if(ce > ne) { // overlapping
                i = j;
                j++;
                count++;
            }
        }
        
        return count;
        
    }
};