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
    
    // Approach:- 2 (Using DFS) | T.C:- O(n*m) | S.C:- O(1)
    /*int di[4] = {-1, 0, 0, 1};
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
    }*/
    
    // Approach:- 3 (Using BFS) | T.C:- O(n*m) | S.C:- O(n*m)
    
    int di[4] = {-1, 0, 0, 1};
    int dj[4] = {0, -1, 1, 0};
    
    void bfs(vector<vector<int>>& grid, int i, int j, int& peri) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = -1; // mark visited
        
        while(!que.empty()) {
            pair<int, int> p = que.front();
            que.pop();
            
            
            
            for(int k = 0; k < 4; k++) {
                int pi = p.first + di[k];
                int pj = p.second + dj[k];
                
                if(pi < 0 || pi >= n || pj < 0 || pj >= m || grid[pi][pj] == 0) {
                    peri++;
                }
                else if(grid[pi][pj] == 1) {
                    grid[pi][pj] = -1;
                    que.push({pi, pj});
                }
            }
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int peri = 0;
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1) {
                    bfs(grid, i, j, peri);
                    return peri;
                }
            }
        }
        
        return -1;
        
    }
};