#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The aim is to find the maximum score by pairing elements from two arrays (nums1 and nums2) and selecting
a specified number of pairs 'k'. We prioritize larger elements from nums2 and calculate the score by
multiplying the sum of selected elements from nums1 with their corresponding elements from nums2. We use
sorting and a rolling window approach to efficiently compute the maximum score.

EXPLANATION:
1) Create a vector of pairs, sort it in non-increasing order based on the first element of each pair.
2) Initialize variables for the maximum score and current sum.
3) Use a min-heap to track the smallest element in the current sum.
4) Iterate through the sorted vector, updating the current sum and checking for the maximum score.
5) Return the maximum score.
*/

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums1.size(); i++)
        {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());
        long long res = 0;
        long long curr = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        while (i < nums1.size())
        {
            curr += v[i].second;
            pq.push(v[i].second);
            if (i >= k - 1)
            {
                res = max(res, curr * v[i].first);
                curr -= pq.top();
                pq.pop();
            }
            i++;
        }
        return res;
    }
};

int main()
{
    return 0;
}