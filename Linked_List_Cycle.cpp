#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We check for the presence of a cycle in a linked list using the Floyd's
Tortoise and Hare algorithm. We employ two pointers, slow and fast,
starting from the head. The fast pointer moves twice as fast as the slow
pointer. If there is a cycle, the fast pointer will eventually catch up to
the slow pointer. If they meet, it indicates the presence of a cycle, and
the function returns true. If they reach the end of the list without meeting,
there is no cycle, and we return false.
*/

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return 1;
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}