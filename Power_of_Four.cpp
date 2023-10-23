#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to determine whether a given integer is a power of four by
recursively dividing it by four until reaching the base case of 1. The base
cases return true for 1 and 4, as they are powers of four. If the number is
zero or not divisible by 4, the function returns false. The recursive approach
leverages the property that any power of four, when repeatedly divided by 4,
eventually becomes 1. The main idea is to check for divisibility by 4 and
continue the division recursively, ensuring that the integer is a power of four.
*/

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 1 or n == 4)
        {
            return 1;
        }
        else if (n <= 0 or n % 4 != 0)
        {
            return 0;
        }
        return isPowerOfFour(n / 4);
    }
};

int main()
{
    return 0;
}