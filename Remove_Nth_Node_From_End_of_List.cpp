#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to remove the nth node from the end of a singly linked list.
We use a two-pointer approach to traverse the list efficiently. Firstly, we
create a dummy node pointing to the head of the list to handle edge cases where
the head needs to be removed. Then, we initialize two pointers, 'first' and
'second', both pointing to the dummy node initially. The 'first' pointer is
moved n+1 steps ahead to create a gap of n nodes between the 'first' and 'second'
pointers. Next, both pointers are advanced simultaneously until the 'first'
pointer reaches the end of the list. At this point, the 'second' pointer will be
pointing to the (n-1)th node from the end. Finally, the target node to be removed
is identified by the 'second' pointer, and its next pointer is adjusted to skip
the nth node. The removed node is then deleted, and the modified list is returned.
*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;
        for (int i = 0; i <= n; i++)
            first = first->next;
        while (first)
        {
            first = first->next;
            second = second->next;
        }
        ListNode *temp = second->next;
        second->next = second->next->next;
        delete temp;
        return dummy->next;
    }
};

int main()
{
    return 0;
}