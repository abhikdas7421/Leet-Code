class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> que;
        for(int &student : students){
            que.push(student);
        }
        
        stack<int> st;
        for(int i = sandwiches.size()-1; i >= 0; i--){
            st.push(sandwiches[i]);
        }
        
        int count = 0;
        while(!que.empty() && count < que.size()){
            if(que.front() == st.top()){
                que.pop();
                st.pop();
                count = 0;
            }
            else{
                que.push(que.front());
                que.pop();
                count++;
            }
        }
        
        return que.size();
    }
};