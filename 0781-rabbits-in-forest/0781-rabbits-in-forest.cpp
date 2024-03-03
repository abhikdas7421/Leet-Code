class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        
        int ans = 0;
        for(int &x : answers) {
            
            if(x == 0) {
                ans++;
            }
            else if(mp[x] > 0) {
                mp[x]--;
            }
            else {
                ans += (x + 1);
                mp[x] = x;
            }
            
            
        }
        
        return ans;
        
    }
};