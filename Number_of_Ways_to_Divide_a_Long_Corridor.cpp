#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The function calculates the number of ways to traverse the corridor
while satisfying specific constraints. We use dynamic programming
with three variables (zero, one, and two) to represent the number of
ways to reach the current position with the last step being 0, 1, or
2 steps, respectively. As the function iterates through each character
in the corridor, we update these variables based on the current character
('S' or something else). The final result is the count of ways to
traverse the corridor with 0 steps at the end.
*/

class Solution
{
public:
    int numberOfWays(string corridor)
    {
        const int MOD = 1e9 + 7;
        int zero = 0;
        int one = 0;
        int two = 1;
        for (char thing : corridor)
        {
            if (thing == 'S')
            {
                zero = one;
                swap(one, two);
            }
            else
                two = (two + zero) % MOD;
        }
        return zero;
    }
};

int main()
{
    return 0;
}