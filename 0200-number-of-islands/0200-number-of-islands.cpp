class Solution {
public:
    int di[4] = {-1, 0, 0, 1};
    int dj[4] = {0, -1, 1, 0};
    
    // Approach:- 1 (Using DFS) | T.C:- O(n*m) | S.C:- O(1)
    /*void dfs(vector<vector<char>>& grid, int i, int j) {
        
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
    }*/
    
    
    // Approach:- 2 (Using BFS) | T.C:- O(n*m) | S.C:- O(n*m)
    void bfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> que;
        que.push({i, j});
        // mark visited
        grid[i][j] = 'v';
        
        while(!que.empty()) {
            
            pair<int, int> p = que.front();
            que.pop();
            
            for(int k = 0; k < 4; k++) {
                int pi = p.first + di[k];
                int pj = p.second + dj[k];
                
                if(pi < 0 || pi >= n || pj < 0 || pj >= m || grid[pi][pj] == '0' || grid[pi][pj] == 'v') {
                    continue;
                }
                else if(grid[pi][pj] == '1') {
                    grid[pi][pj] = 'v'; // mark visited
                    que.push({pi, pj});
                }
            }
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
                    bfs(grid, i, j);
                }
            }
        }
        
        return count;
    } 
};