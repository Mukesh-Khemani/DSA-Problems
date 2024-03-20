#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition is to merge the linked list `list2` into `list1` by first traversing
`list1` to find the nodes at positions `a - 1` and `b`, representing the nodes just
before and after the segment to be replaced, respectively. We then update the `next`
pointer of the node at position `a - 1` to point to the head of `list2`, and identify
the last node of `list2`. Finally, we connect the tail of `list2` to the node following
the segment to be replaced in `list1`, effectively merging the two lists together, and
return the modified `list1`.
*/

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *start = NULL;
        ListNode *end = list1;
        for (int index = 0; index < b; index++)
        {
            if (index == a - 1)
                start = end;
            end = end->next;
        }
        start->next = list2;
        ListNode *tail = list2;
        while (tail->next)
            tail = tail->next;
        tail->next = end->next;
        end->next = NULL;
        return list1;
    }
};

int main()
{
    return 0;
}