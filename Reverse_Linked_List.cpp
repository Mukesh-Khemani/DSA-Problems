#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to reverse a given linked list iteratively. We initialize
three pointers: `current`, `prev`, and `next`, with `current` pointing to
the head of the list and `prev` initially set to `NULL`. Through iteration,
we update `current` to point to the next node, while adjusting pointers to
reverse the direction of traversal. At each step, `current->next` is set to
`prev`, effectively reversing the link direction. Finally, `prev` becomes
the new head of the reversed list, and the function returns it.
*/

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *next = NULL, *current = head, *prev = NULL;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

int main()
{
    return 0;
}