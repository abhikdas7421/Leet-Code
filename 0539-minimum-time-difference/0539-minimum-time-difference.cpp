class Solution
{
    public:
        int toMinute(string time)
        {
            // using in built function of ---> string to int
            // int h = stoi(time.substr(0, 2));
            // int m = stoi(time.substr(3, 2));
            
            int h = ((time[0] - '0') *10) + (time[1] - '0');
            int m = ((time[3] - '0') *10) + (time[4] - '0');

            int totalMinute = h *60 + m;
            
            return totalMinute;
        }

        int findMinDifference(vector<string> &timePoints)
        {
            vector<int> minuteTime;

            int n = timePoints.size();

            for (int i = 0; i < n; i++)
            {
                int minute = toMinute(timePoints[i]);

                minuteTime.push_back(minute);
            }

            sort(minuteTime.begin(), minuteTime.end());

            int miniMin = INT_MAX;

            for (int i = 0; i < minuteTime.size() - 1; i++)
            {
                int m = minuteTime[i + 1] - minuteTime[i];

                miniMin = min(m, miniMin);
            }
            
            int lastDiff = (minuteTime[0] + 1440) - minuteTime[minuteTime.size()-1];
            
            miniMin = min(lastDiff, miniMin);

            return miniMin;
        }
};