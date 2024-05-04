class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        
        sort(people.begin(), people.end());
        
        int boat = 0;
        
        int i = 0;
        int j = n-1;
        
        while(i <= j) {
            
            if(people[j]+people[i] <= limit) {
                i++;
            }
            
            boat++;
            j--;
        }
        
        
        return boat;
    }
};