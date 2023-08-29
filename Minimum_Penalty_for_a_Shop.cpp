#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the problem, we need to return the earliest hour at which the shop must
be closed to incur a minimum penalty. So we iterate through the customer
behaviors while calculating a "penalty" value for each customer. If the
current penalty becomes less than the previous minimum penalty, the start
time for the optimal closing is updated. We ultimately return the start
time with the lowest penalty. We basically prioritize customers staying
('N') over leaving ('Y') and aim to find the closing time with the fewest
penalties.
*/

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int penalty = 0, curPenalty = 0, start = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            char ch = customers[i];
            if (ch == 'Y')
                curPenalty--;
            else
                curPenalty++;
            if (penalty > curPenalty)
            {
                start = i + 1;
                penalty = curPenalty;
            }
        }
        return start;
    }
};

int main()
{
    return 0;
}