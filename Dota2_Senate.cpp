#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In each round, each senator will try to ban the voting rights of the members of the
other party. This process will continue until all the eligible voters are of the
same party.

Solution:
-> We take two queues and append the indices of all the members of the different parties.
-> Then we start iterating the queues and compare the front elements of all the queues.
-> We compare until one of the queue becomes empty and return the name of the party
whose queue is non empty.
Note: We add 'n' to the index which is being appended into the queue as we
want to make sure that each element in a queue is visited exactly one in a round
and to make the value popped and the value appended different.

*/

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> R, D;
        int n = senate.size();
        for (int i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'R')
                R.push(i);
            else
                D.push(i);
        }
        while (R.size() and D.size())
        {
            int r = R.front(), d = D.front();
            R.pop();
            D.pop();
            (r < d) ? R.push(r + n) : D.push(d + n);
        }
        return R.size() ? "Radiant" : "Dire";
    }
};

int main()
{
    return 0;
}