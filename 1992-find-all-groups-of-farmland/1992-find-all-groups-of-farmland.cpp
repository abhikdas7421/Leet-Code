class Solution {
public:
    int di[4] = {1, 0, 0, -1};
    int dj[4] = {0, 1, -1, 0};
    
    // Approach:- 1 (Using DFS) | T.C:- O(n*m) | S.C:- O(1)
    /*void dfs(vector<vector<int>>& land, int i, int j, vector<int>& v) {
        if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || land[i][j] <= 0) {
            return;
        }
        
        land[i][j] = -1;
        
        if(v.empty()) {
            v.push_back(i);
            v.push_back(j);
            v.push_back(i);
            v.push_back(j);
        }
        else if(v[0] >= i && v[1] >= j) {
            v[0] = i;
            v[1] = j;
        }
        else if(v[2] <= i && v[3] <= j) {
            v[2] = i;
            v[3] = j;
        }
        
        for(int k = 0; k < 4; k++) {
            dfs(land, i+di[k], j+dj[k], v);
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 1) {
                    vector<int> v;
                    dfs(land, i, j, v);
                    ans.push_back(v);
                }
            }
        }
        
        return ans;
    }*/
    
    // Approach:- 2 (Using BFS)
    void bfs(vector<vector<int>>& land, int i, int j, vector<int>& v) {
        int n = land.size();
        int m = land[0].size();
        
        queue<pair<int, int>> que;
        que.push({i, j});
        land[i][j] = -1;
        
        v.push_back(i); v.push_back(j);
        v.push_back(i); v.push_back(j);
        
        while(!que.empty()) {
            pair<int, int> p = que.front();
            que.pop();
            
            for(int k = 0; k < 4; k++) {
                int pi = p.first + di[k];
                int pj = p.second + dj[k];
                
                if(pi < 0 || pi >= n || pj < 0 || pj >= m || land[pi][pj] <= 0) {
                    continue;
                }
                else if(land[pi][pj] == 1) {
                    if(v[0] >= pi && v[1] >= pj) {
                        v[0] = pi;
                        v[1] = pj;
                    }
                    else if(v[2] <= pi && v[3] <= pj) {
                        v[2] = pi;
                        v[3] = pj;
                    }
                    
                    land[pi][pj] = -1;
                    que.push({pi, pj});
                }
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 1) {
                    vector<int> v;
                    bfs(land, i, j, v);
                    ans.push_back(v);
                }
            }
        }
        
        return ans;
    }
};