#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to calculate the total amount of money a person
accumulates over a given number of weeks. We divide the total number
of weeks by 7 to determine the number of complete weeks, then compute
the sum of arithmetic progression using the formula for the sum of an
arithmetic series. We then add the sum of complete weeks to the sum of
the remaining days in the last week, where the daily amount increases
linearly starting from the initial amount for Monday.
*/

class Solution
{
public:
    int totalMoney(int n)
    {
        int k = n / 7;
        int firstWeek = 28;
        int lastWeek = 28 + (k - 1) * 7;
        int sum = k * (firstWeek + lastWeek) / 2;

        int monday = 1 + k;
        int finalWeek = 0;
        for (int i = 0; i < n % 7; i++)
            finalWeek += monday + i;
        return sum + finalWeek;
    }
};

int main()
{
    return 0;
}