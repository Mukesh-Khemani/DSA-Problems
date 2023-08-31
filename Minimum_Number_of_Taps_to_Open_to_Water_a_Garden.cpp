#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the problem, we need to calculate the minimum number of taps needed
to water a garden of plants, where each tap has a certain range. So we
iterate through the tap ranges and stores the effective range of each
tap in an arr array. Then, we use a greedy approach to simulate watering
the garden while keeping track of the farthest point reached. We return
the minimum number of taps required to cover the entire garden, or -1 if
it's not possible to cover the entire garden.
*/

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> arr(n + 1, 0);
        for (int i = 0; i < ranges.size(); i++)
        {
            if (ranges[i] == 0)
                continue;
            int left = max(0, i - ranges[i]);
            arr[left] = max(arr[left], i + ranges[i]);
        }
        int end = 0, count = 0, upperLimit = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i > end)
            {
                if (upperLimit <= end)
                    return -1;
                end = upperLimit;
                count++;
            }
            upperLimit = max(upperLimit, arr[i]);
        }
        return count + (end < n);
    }
};

int main()
{
    return 0;
}