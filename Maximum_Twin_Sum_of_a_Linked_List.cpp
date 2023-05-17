#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The main intuition in this question was to flip or reverse the second half of
the linked list so that the maximum pairSm can be easily calculated in a single traversal.

Working:
The pairSum function calculates the maximum sum of pairs from a linked list. It uses the
two-pointer technique to find the middle node and reverses the second half of the list. Then,
it iterates through the original and reversed lists simultaneously, calculating the maximum sum
of each pair. Finally, it returns the maximum sum. The function has a time complexity of O(n)
and a space complexity of O(1).
*/
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        int maxSum = 0;
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *next = NULL, *prev = NULL;
        while (slow != NULL)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        while (prev)
        {
            maxSum = max(maxSum, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }
        return maxSum;
    }
};

int main()
{
    return 0;
}