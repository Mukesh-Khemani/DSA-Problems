#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the given code is to swap the values of two nodes in a
linked list based on their positions, represented by the variable k.

Explanation:
-> The code initializes pointers left and right to keep track of the nodes to be swapped.
It also uses a variable x to temporarily store the value of the left node.
-> The while loop iterates through the linked list, incrementing the variable x as it
progresses. When x becomes equal to k, the left pointer is assigned to the corresponding
node. As the loop continues, the right pointer is moved further into the list.
-> After the loop, the value of the left node is stored in x, allowing for a temporary swap.
Then, the code swaps the values between the left and right nodes, ensuring the correct
values are exchanged.
->Finally, the modified linked list is returned.
*/

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int x = 0;
        ListNode *Head = head;
        ListNode *left = NULL;
        ListNode *right = head;
        while (Head)
        {
            x++;
            if (x == k)
                left = Head;
            if (x > k)
                right = right->next;
            Head = Head->next;
        }
        x = left->val;
        left->val = right->val;
        right->val = x;
        return head;
    }
};

int main()
{
    return 0;
}