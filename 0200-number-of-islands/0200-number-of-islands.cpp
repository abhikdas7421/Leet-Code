class Solution {
public:
    int di[4] = {-1, 0, 0, 1};
    int dj[4] = {0, -1, 1, 0};
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || grid[i][j] == -1) {
            return;
        }
        
        grid[i][j] = -1;
        
        for(int k = 0; k < 4; k++) {
            dfs(grid, i+di[k], j+dj[k]);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
        
    }
};