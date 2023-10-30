#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The main intuition is to calculate the weight (number of set bits) of
an integer using the Brian Kernighan's algorithm. In the class we have
a static compare function that compares two integers based on their
weights, and if the weights are equal, we compare the integers themselves.
The main function sortByBits sorts an input vector of integers arr using
the compare function as the custom comparator. This algorithm sorts the
integers based on the number of set bits, prioritizing those with fewer
set bits.
*/

class Solution
{
    static int helper(int n)
    {
        int weight = 0;
        while (n > 0)
        {
            weight++;
            n &= (n - 1);
        }
        return weight;
    }
    static bool compare(int a, int b)
    {
        if (helper(a) == helper(b))
            return a < b;
        return helper(a) < helper(b);
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};

int main()
{
    return 0;
}