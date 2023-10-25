#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We employ a bottom-up approach, starting from the base case (n=1) and
iteratively calculating the grammar symbols for each subsequent row
until reaching the desired row n. We use a loop to determine the symbol
at the kth position by considering the total number of symbols in the
row and adjusting the position based on whether it falls in the first
or second half. The symbol alternates between 0 and 1, representing the
binary grammar sequence.
*/

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        int symbol = 1;
        for (int row = n; row > 1; row--)
        {
            int total = pow(2, (row - 1));
            int half = total / 2;
            if (k > half)
            {
                symbol = 1 - symbol;
                k -= half;
            }
        }
        if (symbol)
            return 0;
        return 1;
    }
};

int main()
{
    return 0;
}