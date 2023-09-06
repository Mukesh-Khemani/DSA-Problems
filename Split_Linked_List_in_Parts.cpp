#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We have to divide a linked list into approximately equal parts. So we
first calculate the size of the list and determine the number of nodes
in each part. Then, we iterate through the list, cutting it into segments,
and store the head nodes of each segment in a vector. This division allows
for efficient processing or analysis of the linked list's data in smaller,
manageable portions.
*/

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> result(k, NULL);
        int size = 0;
        for (ListNode *node = head; node; node = node->next)
            size++;
        int n = size / k, r = size % k;
        ListNode *node = head, *prev = NULL;
        for (int i = 0; node && i < k; i++, r--)
        {
            result[i] = node;
            for (int j = 0; j < n + (r > 0); j++)
            {
                prev = node;
                node = node->next;
            }
            prev->next = NULL;
        }
        return result;
    }
};

int main()
{
    return 0;
}