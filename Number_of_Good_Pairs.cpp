#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind this problem is to count the number of identical
pairs in a given vector of integers efficiently. So we use a map to keep
track of the frequency of each number as it iterates through the array.
For each encountered number, we increment the result by the current count
of that number in the map and then increment the count. The approach takes
advantage of the fact that for each new occurrence of a number, it contributes
to the count of identical pairs for all previous occurrences of the same number.
*/

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        map<int, int> map;
        int result = 0;
        for (int num : nums)
        {
            result += map[num];
            map[num]++;
        }
        return result;
    }
};

int main()
{
    return 0;
}