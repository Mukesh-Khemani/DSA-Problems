#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find Diagonal Order that takes a 2D vector of
integers (nums) as input. It uses a queue to traverse the elements
of the 2D vector in a diagonal order, starting from the top-left
corner. The queue stores pairs of row and column indices, and at each
iteration, the front element is dequeued, and the corresponding element
from the input vector is added to the result vector. Additionally,
we check and enqueue the next elements on the diagonal path, considering
edge cases to avoid out-of-bounds errors. The result is a vector
containing the elements of the input matrix traversed in a diagonal order.
*/

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> ans;
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            ans.push_back(nums[r][c]);
            if (c == 0 and r + 1 < nums.size())
                q.push({r + 1, c});
            if (c + 1 < nums[r].size())
                q.push({r, c + 1});
        }
        return ans;
    }
};

int main()
{
    return 0;
}