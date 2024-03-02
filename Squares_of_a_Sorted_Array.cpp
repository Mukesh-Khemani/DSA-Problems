#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to return the squares of the elements in the input vector `nums`
in sorted order. We achieve this by first iterating through each element in `nums`,
squaring each element, and storing the squared values in a separate vector `ans`.
Then, we sort the `ans` vector using the `sort` function to ensure that the squared
values are arranged in ascending order. Finally, we return the sorted vector `ans`.
*/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans;
        for (int i : nums)
            ans.push_back(i * i);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    return 0;
}