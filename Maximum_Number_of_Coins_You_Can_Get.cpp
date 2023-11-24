#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is to maximize the number of coins
collected by selecting every third element from the sorted vector
(starting from the end) since the other two players always leave the
minimum of the three piles. By iterating over the vector with a step
of 2 from the last third of the sorted piles, we accumulate the values
of the selected piles into the variable ans. Ultimately, we return the
total accumulated value, representing the maximum number of coins that
can be obtained by strategically selecting piles in a game scenario.
*/

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        int ans = 0;
        for (int i = piles.size() / 3; i < piles.size(); i += 2)
            ans += piles[i];
        return ans;
    }
};

int main()
{
    return 0;
}