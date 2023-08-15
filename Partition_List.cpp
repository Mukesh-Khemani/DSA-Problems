#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the problem, we have to partition a singly linked list into two segments:
one with elements less than a given value x and the other with elements greater
than or equal to x. We accomplish this by iterating through the original list
and using two dummy nodes (Prev and Next) to construct the partitioned segments.
As each node is examined, we assign it to the appropriate segment based on its
value compared to x. After the traversal, the two segments are linked together
by updating pointers, resulting in a new linked list that fulfills the partitioning
condition.
*/

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode Prev(0), Next(0);
        ListNode *prev_curr = &Prev;
        ListNode *next_curr = &Next;
        while (head)
        {
            if (head->val >= x)
            {
                next_curr->next = head;
                next_curr = head;
            }
            else
            {
                prev_curr->next = head;
                prev_curr = head;
            }
            head = head->next;
        }
        next_curr->next = NULL;
        prev_curr->next = Next.next;
        return Prev.next;
    }
};

int main()
{
    return 0;
}