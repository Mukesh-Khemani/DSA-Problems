#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find and return an integer that appears more
than 25% of the time in a given sorted array. We iterate through
the array, checking consecutive subsequences of size `arr.size()/4`.
If an integer is found that appears more than 25% of the time, it
is returned.
*/

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int size = arr.size() / 4;
        for (int i = 0; i < arr.size() - size; i++)
        {
            if (arr[i] == arr[i + size])
                return arr[i];
        }
        return -1;
    }
};

int main()
{
    return 0;
}