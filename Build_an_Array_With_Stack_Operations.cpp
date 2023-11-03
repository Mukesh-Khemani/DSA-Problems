#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The main intuition is to find a sequence of operations to transform
an initially empty array into a target array using a specific set of
operations ("Push" and "Pop"). So we iterate over the target array,
pushing elements onto the result vector and simulating the required
operations. For each element in the target array, we push `Push` and
`Pop` operations until the current element is reached, effectively
simulating the process of constructing the target array.
*/

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> res;
        int i = 0;
        for (int num : target)
        {
            while (i < num - 1)
            {
                res.push_back("Push");
                res.push_back("Pop");
                i++;
            }
            res.push_back("Push");
            i++;
        }
        return res;
    }
};

int main()
{
    return 0;
}