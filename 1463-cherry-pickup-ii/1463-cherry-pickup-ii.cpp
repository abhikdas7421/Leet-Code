class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp) {
        // base case
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) {
            return 0;
        }
        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        if(i == grid.size()-1) {
            if(j1 == j2) {
                return grid[i][j1];
            }
            
            return grid[i][j1] + grid[i][j2];
        }
        
        int maxi = 0;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                if(j1 == j2) {
                   maxi = max(maxi,grid[i][j1] +  solve(grid, i+1, j1+dj1, j2+dj2, dp));
                }
                else{
                    maxi = max(maxi,grid[i][j1] + grid[i][j2] +  solve(grid, i+1, j1+dj1, j2+dj2, dp));
                }
            }
        }
        
        return dp[i][j1][j2] = maxi;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return solve(grid, 0, 0, grid[0].size()-1, dp);
    }
};