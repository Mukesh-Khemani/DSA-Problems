#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We need to return the average salary of employees excluding the minimum and maximum salary.

WORKING:
Approach-1:
In this, we sort the array and find the sum of all the elements in the array.Then we subtract
the first (Minimum salary) and the last element (Maximum salary) from
the sum and return their average. The time complexity of this approach O(nlogn).

Approach-2:
As we only need the maximum and the minimum salaries, there is no need to sort the array.
We can just keep a track of the minimum and maximum salaries. This will take O(N) time.
(Note: In the last step, we divide the sum by 'n-2.0' as we need to return the ans in double)
*/

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int n = salary.size(), sum = 0, Min = INT_MAX, Max = INT_MIN;
        for (int i : salary)
        {
            Max = Max < i ? i : Max;
            Min = Min > i ? i : Min;
            sum += i;
        }
        sum -= (Min + Max);
        return sum / (n - 2.0);
    }
};

int main()
{
    return 0;
}