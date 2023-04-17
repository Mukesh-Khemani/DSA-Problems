#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this question, we just have to compare each element of the 'candies' array with the
maximum number of candies in the array.

SOLUTION:
- First, we find the maximum number in the array 'candies'.
- Then, we iterate the entire 'candies' array and compare the sum of the
current element and the 'extracandies' with the maximum number of candies.
- If the sum is more than equal to maximum number of candies, then push 'true'
in the resulting array.
- Else push 'false'.
*/

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> v;
        int max = *max_element(candies.begin(), candies.end());
        for (int i : candies)
        {
            if (i + extraCandies >= max)
                v.push_back(true);
            else
                v.push_back(false);
        }
        return v;
    }
};

int main()
{
    return 0;
}