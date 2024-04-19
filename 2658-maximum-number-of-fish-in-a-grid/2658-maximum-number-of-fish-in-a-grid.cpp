class Solution {
public:
    int di[4] = {-1, 0, 0, 1};
    int dj[4] = {0, -1, 1, 0};
    
    void bfs(vector<vector<int>>& grid, int i, int j, int& fish) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        queue<pair<int, int>> que;
        que.push({i, j});
        
        fish += grid[i][j];
        grid[i][j] *= -1;
        
        while(!que.empty()) {
            
            pair<int, int> p = que.front();
            que.pop();
            
            for(int k = 0; k < 4; k++) {
                int pi = p.first + di[k];
                int pj = p.second + dj[k];
                
                if(pi < 0 || pi >= n || pj < 0 || pj >= m || grid[pi][pj] <= 0) {
                    continue;
                }
                else if(grid[pi][pj] > 0) {
                    fish += grid[pi][pj];
                    grid[pi][pj] *= -1;
                    que.push({pi, pj});
                }
            }
        }
        
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int maxFish = 0;
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] > 0) {
                    
                    int currFish = 0;
                    bfs(grid, i, j, currFish);
                    maxFish = max(maxFish, currFish);
                }
            }
        }
        
        return maxFish;
        
    }
};