#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to check whether a given integer `n` is a power of two.
We start by handling base cases: if `n` is 1, we return true immediately
since 1 is a power of two. If `n` is 0 or odd, we return false, as powers
of two are always even and greater than zero. For all other cases, the
function recursively divides `n` by 2 until it either reaches 1 (in which
case `n` is a power of two) or encounters an odd number, indicating `n` is
not a power of two.
*/

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n % 2 or n == 0)
        {
            return 0;
        }
        else
        {
            return isPowerOfTwo(n / 2);
        }
    }
};

int main()
{
    return 0;
}