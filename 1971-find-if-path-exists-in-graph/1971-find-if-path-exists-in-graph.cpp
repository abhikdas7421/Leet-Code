class Solution {
public:
    bool check(unordered_map<int, vector<int>>& mp, int s, int d, vector<bool>& visited) {
        if(s == d) return true;
        
        if(visited[s] == true) return false;
        
        visited[s] = true;
        
        for(auto &node : mp[s]) {
            if(check(mp, node, d, visited) == true) return true;
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp; // adjacency list
        
        for(vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            //bidirectional graph
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        
        
        
        return check(mp, source, destination, visited);
    }
};