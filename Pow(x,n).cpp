#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the given problem lies in the concept of divide-and-conquer
to efficiently compute the power of x raised to n. The recursive function, myPow,
takes advantage of the observation that x^n can be expressed as x^(n/2) * x^(n/2)
if n is even or as x * x^((n-1)/2) * x^((n-1)/2) if n is odd. By recursively dividing
the problem into smaller subproblems, where n is halved at each step, the code
significantly reduces the number of multiplications required to calculate the final
result. Special cases for x=0, n=0, and handling negative exponents ensure correct
results and optimizations.
*/

class Solution
{
public:
    double myPow(double x, long long int n)
    {
        if (x == 0)
            return 0;
        if (n == 0)
            return 1;
        if (n < 0)
        {
            n = -n;
            x = 1 / x;
        }
        if (n == 1)
            return x;
        return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }
};

int main()
{
    return 0;
}