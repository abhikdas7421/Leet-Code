class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> result(n, 0);
        
        sort(deck.begin(), deck.end());
        
        int skip = false;
        
        int i = 0; // deck
        int j = 0; // result
        
        while(i < n) {
            
            if(result[j] == 0) {
                
                if(skip == false) {
                    result[j] = deck[i];
                    i++;
                }
                
                
                skip = !skip;
            }
            
            j = (j+1)%n;
        }
        
        return result;
    }
};