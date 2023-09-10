#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we need to count all valid pickup/delivery possible
sequences such that delivery(i) is always after of pickup(i). We
achieve this using a formula and modular arithmetic to handle large
values of 'n' without causing integer overflow.
*/

class Solution
{
public:
    int countOrders(int n)
    {
        long long orders = 1;
        for (int i = 2; i <= n; i++)
        {
            orders = (orders * (2 * i - 1) * i) % 1000000007;
        }
        return (int)orders;
    }
};

int main()
{
    return 0;
}