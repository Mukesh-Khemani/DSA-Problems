#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the solution is to break down the problem into smaller subproblems.
By considering each pair of nodes, we can swap their positions and recursively solve
the subproblem for the remaining nodes.

Solution:
1) The code first checks the base case, which is when the linked list is empty or contains
only one node. In such cases, there is no need to swap any nodes, so the function directly
returns the head.

2) For the remaining cases, the code creates a temporary node temp to store the second node
of the current pair. It then updates the next pointer of the head node to point to the result
of recursively calling swapPairs on the next pair of nodes, which is obtained by accessing
head->next->next.

3) After updating the next pointer of the head node, the next pointer of temp is set to the
head node, effectively swapping their positions.

4) Finally, the modified head node is set to temp, and the updated linked list with swapped
pairs is returned.
*/

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};

int main()
{
    return 0;
}