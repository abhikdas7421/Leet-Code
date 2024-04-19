class Solution {
public:
    
    int di[4] = {-1, 0, 0, 1};
    int dj[4] = {0, -1, 1, 0};
    
    // Approach:- 1 (Using DFS) | T.C:- O(n*m) | S.C:- O(1)
    /*void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        
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
    }*/
    
    // Approach:- 2 (Using BFS) | T.C:- O(n*m) | S.C:- O(n*m)
    void bfs(vector<vector<int>>& grid, int i, int j, int& area) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = -1;
        area++;
        
        while(!que.empty()) {
            
            pair<int, int> p = que.front();
            que.pop();
            
            for(int k = 0; k < 4; k++) {
                int pi = p.first + di[k];
                int pj = p.second + dj[k];
                
                if(pi < 0 || pi >= n || pj < 0 || pj >= m || grid[pi][pj] == 0 || grid[pi][pj] == -1) {
                    continue;
                }
                else if(grid[pi][pj] == 1) {
                    grid[pi][pj] = -1;
                    area++;
                    que.push({pi, pj});
                }
            }
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
                    bfs(grid, i, j, currArea);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;
    }
};