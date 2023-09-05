#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem defines a function copyRandomList that creates a deep copy of a
linked list containing nodes with both next and random pointers. We achieve
this by first iterating through the original list, creating a new node for
each original node, and storing a mapping between the original nodes and
their corresponding copied nodes in a map. Then, in the second pass, we update
the next and random pointers of the copied nodes based on the mapping created
earlier.
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        map<Node *, Node *> map;
        Node *temp = head;
        while (temp)
        {
            map[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            map[temp]->next = map[temp->next];
            map[temp]->random = map[temp->random];
            temp = temp->next;
        }
        return map[head];
    }
};

int main()
{
    return 0;
}