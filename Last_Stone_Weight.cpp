#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this question, in each array traversal, we need to find the maximum_element
and the second_maximum_element. So we need an algorithm which returns these elements
in the shortest time and is the most efficient. We have two choices:

1) To sort the array in ascending order and pich the last two elements.
This will be a complex task as we also need to insert the absolute difference
into the array if both the maximum and second_maximum are not equal.

2) To use Priority Queue (Heap): this is comparatively easy to implement
as it returns the maximum element whenever we perform a pop operation in
O(logN), and all the operations can be performed in O(logN) time complexity.
*/

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a != b)
                q.push(abs(a - b));
        }
        return q.size() ? q.top() : 0;
    }
};

int main()
{
    return 0;
}