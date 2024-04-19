class Solution {
public:
    // Approach:- 1
    /*int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1) {
                    
                    // row-1
                    if(i-1 < 0 || grid[i-1][j] == 0) {
                        perimeter++;
                    }
                    
                    // row+1
                    if(i+1 >= n || grid[i+1][j] == 0) {
                        perimeter++;
                    }
                    
                    // col-1
                    if(j-1 < 0 || grid[i][j-1] == 0) {
                        perimeter++;
                    }
                    
                    // col+1
                    if(j+1 >= m || grid[i][j+1] == 0) {
                        perimeter++;
                    }
                }
            }
        }
        
        return perimeter; 
    }*/
    
    // Approach:- 2 (Using DFS)
    int di[4] = {-1, 0, 0, 1};
    int dj[4] = {0, -1, 1, 0};
    
    void dfs(vector<vector<int>>& grid, int i, int j, int &peri) {
        
        // out of island
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            peri++;
            return;
        }
        
        // already visited
        if(grid[i][j] == -1) return;
        
        grid[i][j] = -1; // mark visited
        
        for(int k = 0; k < 4; k++) {
            dfs(grid, i+di[k], j+dj[k], peri);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int peri = 0;
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, peri);
                    return peri;
                }
            }
        }
        
        return -1;
    }
};