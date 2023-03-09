#include <bits/stdc++.h>
using namespace std;

/*
ALGORITHM:
We are using two pointers, fast and slow where 'fast' traverses two nodes at a time and 'slow' pointer traverses
one node at a time. If both the pointers meet, this means that their exists a loop in the linked list.

WORKING:
-> At first, we initialise two pointers fast and slow which point to the head of the linked list. 
-> Then we move the fast pointer two nodes at a time and the slow pointer one node at a time.
-> If the fast pointer reaches to  the end of the linked list, then there is no cycle in the list. 
Hence, return we  NULL.
-> But if both the pointers meet at any node, then there is a cycle in the list as at that point, 
the fast pointer must have completed some 'n' (where n can be any positive integer) number of cycles more than slow.
-> At this point we have to find the starting point of the cycle. And for that, we initialize the slow pointer to 
the head of the list and keep the fast pointer at the node of intersection.
-> Move both pointers one step at a time until they meet and their node of intersection is the start of the cycle
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
                ListNode* fast=head;
                ListNode* slow=head;
                while (fast!=NULL && fast->next!=NULL){
                fast = fast->next->next;
                slow = slow->next;
                
                if (fast == slow){
                    ListNode *slow2 = head; 
                    while (slow2 != slow){
                        slow = slow->next;
                        slow2 = slow2->next;
                    }
                    return slow;
                }
            }
            return NULL;
    }
    
};

int main()
{
    return 0;
}