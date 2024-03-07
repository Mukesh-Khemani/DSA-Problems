#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The solution aims to find the middle node of a linked list by utilizing a
two-pointer approach. We initialize two pointers, `fast` and `slow`, both
pointing to the head of the linked list. The `fast` pointer advances two
nodes at a time while the `slow` pointer advances one node at a time. This
double speed of the `fast` pointer allows it to traverse the list faster
than the `slow` pointer. By the time the `fast` pointer reaches the end of
the list (or beyond), the `slow` pointer will be at the middle of the list.
*/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    return 0;
}