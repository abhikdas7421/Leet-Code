class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int>>> timeMeetings;
        
        for(vector<int> &meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];
            
            timeMeetings[time].push_back({person1, person2});
        }
        
        
        vector<bool> knowSecret(n, false);
        knowSecret[0] = true;
        knowSecret[firstPerson] = true;
        
        for(auto &it : timeMeetings) {
            int time = it.first;
            vector<pair<int, int>> meets = it.second;
            
            unordered_map<int, vector<int>> adj;
            queue<int> que;
            unordered_set<int> alreadyAdded;
            
            for(auto &[p1, p2] : meets) {
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);
                
                if(knowSecret[p1] && alreadyAdded.find(p1) == alreadyAdded.end()) {
                    que.push(p1);
                    alreadyAdded.insert(p1);
                }
                
                if(knowSecret[p2] == true && alreadyAdded.find(p2) == alreadyAdded.end()) {
                    que.push(p2);
                    alreadyAdded.insert(p2);
                }
            }
            
            while(!que.empty()) {
                int person = que.front();
                que.pop();
                
                for(auto &nextPerson : adj[person]) {
                    if(!knowSecret[nextPerson]) {
                        knowSecret[nextPerson] = true;
                        que.push(nextPerson);
                    }
                }
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(knowSecret[i] == true) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};























