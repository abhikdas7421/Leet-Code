class Solution
{
    public:
        int numberOfBeams(vector<string> &bank)
        {
            int prevRowCurr = 0;
            int currRowCurr = 0;
            int numOfBeams = 0;

            for (auto s : bank)
            {

                for (auto c : s)
                {
                    if (c == '1')
                    {
                        ++currRowCurr;
                    }
                }

                

                if (currRowCurr != 0)
                {
                    numOfBeams += (prevRowCurr * currRowCurr);
                    prevRowCurr = currRowCurr;
                }
                currRowCurr = 0;
            }

            return numOfBeams;
        }
};