#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We need to find the number of 'good numbers' of 'n' digits.A digit string
is good if the digits (0-indexed) at even indices are even and the digits
at odd indices are prime (2, 3, 5, or 7). The number of even indices will
always be greater than or equal to the number of odd indices.

So we have to multiply 5 (as their are 5 single digit even numbers i.e.
0,2,4,6,8) to the power of even indices with 4 (as their are 4 single digit
prime numbers i.e. 2,3,5,7). And in order to prevent integer overflow at any
stage, we return its modulo (pow(10,9) + 7).
*/

class Solution
{
    int mod = 1000000007;
    long long power(int x, long long y)
    {
        if (y == 0)
            return 1;
        long long ans = power(x, y / 2);
        ans *= ans;
        ans %= mod;
        if (y % 2)
        {
            ans *= x;
            ans %= mod;
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n)
    {
        return (power(5, n / 2 + n % 2) * power(4, n / 2)) % mod;
    }
};

int main()
{
    return 0;
}