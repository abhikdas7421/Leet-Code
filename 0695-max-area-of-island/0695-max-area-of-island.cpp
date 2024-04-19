class Solution {
public:
    
    int di[4] = {-1, 0, 0, 1};
    int dj[4] = {0, -1, 1, 0};
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        
        // already visited cell
        if(grid[i][j] == -1) return;
        
        // mark visited this cell
        grid[i][j] = -1;
        area++;
        
        for(int k = 0; k < 4; k++) {
            dfs(grid, i+di[k], j+dj[k], area);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int maxArea = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1) {
                    int currArea = 0;
                    dfs(grid, i, j, currArea);
                    
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;
    }
};