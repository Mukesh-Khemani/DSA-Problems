#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we have to find if the numbers of the array can form
an Arithmetic Progression in any order i.e. we can manipulate the order
of the numbers of the array.

APPROACH:
The solution sorts the array to ensure that the elements are in increasing
order. Then, it checks if the difference between consecutive elements
remains constant throughout the array, which is a characteristic of an
arithmetic progression.
*/

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int x = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++)
        {
            if (x != arr[i] - arr[i - 1])
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}