class Solution {
public:
    typedef pair<long long, int> p;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        
        sort(meetings.begin(), meetings.end());
        
        vector<int> roomUsedCount(n, 0);
        
        priority_queue<p, vector<p>, greater<p>> usedRooms;
        
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        
        for(int room = 0; room < n; room++) {
            availableRooms.push(room);
        }
        
        for(vector<int> &meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end-start;
            
            while(!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                
                availableRooms.push(room);
            }
            
            if(!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                
                usedRooms.push({end, room});
                roomUsedCount[room]++;
            }
            else {
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                
                usedRooms.pop();
                
                usedRooms.push({endTime + duration, room});
                roomUsedCount[room]++;
            }
        }
        
        
        int resultRoom = -1;
        int maxUse = 0;
        
        for(int room = 0; room < n; room++) {
            if(roomUsedCount[room] > maxUse) {
                resultRoom = room;
                maxUse = roomUsedCount[room];
            }
        }
        return resultRoom;
    }
};
















