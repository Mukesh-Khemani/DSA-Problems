#include <bits/stdc++.h>
using namespace std;
// without having the head of the linkedlist
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};

int main()
{
    return 0;
}