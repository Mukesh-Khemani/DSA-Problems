#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to determine if there exists an integer 'pivot' such that
it divides the sequence of consecutive positive integers from 1 to 'n' into
two equal parts. We compute the sum of all integers from 1 to 'n' using the
formula for the sum of an arithmetic series. Then, we calculate the square
root of this sum to obtain the potential pivot integer. If the square of this
pivot integer equals the sum, we imply that the sequence can be divided into t
wo equal parts by this pivot, and thus, we return the pivot integer. Otherwise,
if there is no such pivot, we return -1.
*/

class Solution
{
public:
    int pivotInteger(int n)
    {
        const int sum = (n * (n + 1) / 2);
        const int pivot = sqrt(sum);

        return pivot * pivot == sum ? pivot : -1;
    }
};

int main()
{
    return 0;
}