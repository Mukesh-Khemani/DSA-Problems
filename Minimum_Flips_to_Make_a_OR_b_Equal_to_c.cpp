#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we need to find the minimum number of bit flips required to convert the result
of 'a OR b' to 'c'. We can use bit manipulation to solve this problem.

APPROACH:
We iterate through the bits of a, b, and c, checking if a bit flip is needed at each position.
The count of required bit flips is incremented based on specific conditions. The loop continues
until all bits have been processed. Finally, we return the total count of bit flips.
*/

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int result = 0;
        while (a or b or c)
        {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;
            if ((bitA | bitB) != bitC)
            {
                if (bitA & bitB)
                    result += 2;
                else
                    result++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return result;
    }
};

int main()
{
    return 0;
}