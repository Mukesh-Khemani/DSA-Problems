#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the kth largest element in an array using a max-heap
(priority queue). We start by inserting all elements into the heap. After
adjusting for the 0-based indexing, we iteratively remove the smallest
element (k-1) times, leaving the kth largest element at the top of the heap,
which is then returned as the result. This approach efficiently finds the
desired element by leveraging the max-heap property, ensuring that the top
element is always the largest among the remaining elements.
*/

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (int it : nums)
            pq.push(it);
        k--;
        while (k--)
            pq.pop();
        return pq.top();
    }
};

int main()
{
    return 0;
}