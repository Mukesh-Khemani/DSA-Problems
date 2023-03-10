#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We have to return a random node's value from the linked list
and each node must have the same probability of being chosen.

APPROACH:
-> First we have to find the number of nodes in the linked list.
-> Then, take a random number and take its remainder with the size 
of the list.
-> Then, iterate the list until the random node is reached.
Return its value.
*/

class Solution {
public:
    ListNode *RandomNode;
    int size=0;

    Solution(ListNode* head){
        RandomNode=head;
        while(head){
            head=head->next;
            size++;
        }
    }
    
    int getRandom() {
        int n=rand()%size;
        ListNode* head = RandomNode;
        while(n--){
            head=head->next;
        }
        return head->val;
    }
};


int main()
{
    return 0;
}