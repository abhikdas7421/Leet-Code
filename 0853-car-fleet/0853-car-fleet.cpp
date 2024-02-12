class Solution {
public:
    static bool myCmp(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.first < p2.first;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        vector<pair<int, int>> car;
        for(int i = 0; i < n; i++) {
            pair<int, int> p = make_pair(position[i], speed[i]);
            car.push_back(p);
        }
        sort(car.begin(), car.end(), myCmp);
        
        stack<float> st;
        for(int i = 0; i < n; i++) {
            float pos = car[i].first;
            float speed = car[i].second;
            float time = (target-pos)/speed;
            
            while(!st.empty() && st.top() <= time) {
                st.pop();
            }
            st.push(time);
        }
        
        int noOfFleet = st.size();
        return noOfFleet;
    }
};