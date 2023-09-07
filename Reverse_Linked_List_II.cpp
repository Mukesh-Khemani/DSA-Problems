#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given problem needs is to reverse a sublist of a linked list between specified
positions `left` and `right`. So we employ a `dummy` node to handle the case when
`left` is equal to 1. We initialize a `prev` pointer to reach the node before position
`left` and a `curr` pointer to point to the node at position `left`. Then, we reverse
the sublist iteratively by temporarily holding the next node in `temp`, disconnecting
`curr` from the following nodes, connecting temp to `prev`, and updating prev->next
to point to `temp`. This process effectively reverses the direction of the sublist
between `left` and `right`.
*/

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head or left == right)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        for (int i = 0; i < left - 1; i++)
            prev = prev->next;
        ListNode *curr = prev->next;
        for (int i = 0; i < right - left; i++)
        {
            ListNode *temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy->next;
    }
};

int main()
{
    return 0;
}