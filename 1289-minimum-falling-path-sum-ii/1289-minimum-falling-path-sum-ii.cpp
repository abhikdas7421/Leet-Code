class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int nextMin1Col = -1;
        int nextMin2Col = -1;
        
        int nextMin1Val = -1;
        int nextMin2Val = -1;
        
        for (int col = 0; col < n; col++) {

            if(nextMin1Col == -1 || grid[n - 1][col] <= nextMin1Val) {
                nextMin2Col = nextMin1Col;
                nextMin2Val = nextMin1Val;
                
                nextMin1Col = col;
                nextMin1Val = grid[n-1][col];
                
            } else if(nextMin2Col == -1 || grid[n - 1][col] <= nextMin2Val) {
                nextMin2Col = col;
                nextMin2Val = grid[n-1][col];
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            
            int min1Col = -1;
            int min2Col = -1;
            
            int min1Val = -1;
            int min2Val = -1;
            
            for (int col = 0; col < n; col++) {
                
                int ans;
                if(col != nextMin1Col) {
                    ans = grid[row][col] + nextMin1Val;
                } else {
                    ans = grid[row][col] + nextMin2Val;
                }
                
                if(min1Col == -1 || ans <= min1Val) {
                    min2Col = min1Col;
                    min2Val = min1Val;
                    
                    min1Col = col;
                    min1Val = ans;
                } else if(min2Col == -1 || ans <= min2Val) {
                    min2Col = col;
                    min2Val = ans;
                }
            }
                            
            nextMin1Col = min1Col;
            nextMin1Val = min1Val;
            
            nextMin2Col = min2Col;
            nextMin2Val = min2Val;
                
        }

        // Return the minimum from the first row
        return nextMin1Val;
    }
};