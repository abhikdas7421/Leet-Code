class Solution
{
    public:
        int numberOfBeams(vector<string> &bank)
        {
            int r1 = 0;
            int r2 = 0;
            int numOfBeams = 0;

            for (int i = 0; i < bank.size(); ++i)
            {

                for (int j = 0; j < bank[i].size(); ++j)
                {
                    if (bank[i][j] == '1')
                    {
                        ++r2;
                    }
                }

                numOfBeams += (r1 *r2);

                if (r2 != 0)
                {
                    r1 = r2;
                }
                r2 = 0;
            }

            return numOfBeams;
        }
};