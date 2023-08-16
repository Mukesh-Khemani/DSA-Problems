#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the problem, we employ a double-ended queue (deque) to track the indices
of potential maximum elements within sliding windows of size k as they traverse
the input vector nums. By maintaining a deque that stores only relevant indices,
removing unnecessary elements, and ensuring that the maximum candidate elements
are consistently positioned at the front of the deque, we identify the maximum
element for each window and populate the result vector.
*/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!q.empty() and q.front() == i - k)
                q.pop_front();
            while (!q.empty() and nums[i] > nums[q.back()])
                q.pop_back();
            q.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}