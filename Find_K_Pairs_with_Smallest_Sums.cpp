#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the given problem, we find the k smallest pairs from two input arrays, nums1 and nums2,
based on their sums. It uses a priority queue to keep track of the k smallest pairs.

So we iterate through every pair combination of nums1 and nums2 and calculates the sum.
If the priority queue size is less than k, the current pair is pushed into the priority queue.
If the sum is smaller than the largest sum in the priority queue, the largest sum is removed
and the current pair is inserted into the priority queue.
*/

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                int sum = nums1[i] + nums2[j];
                if (pq.size() < k)
                    pq.push({sum, {nums1[i], nums2[j]}});
                else if (sum < pq.top().first)
                {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else
                    break;
            }
        }
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}