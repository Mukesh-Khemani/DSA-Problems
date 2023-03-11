#include <bits/stdc++.h>
using namespace std;

/*
APPROACH:
-> Find the size of the linked list. Then, find the middle element (=size/2) of the linked list.
-> Create a new node with the middle element as its value (This is the root of the BST).
-> This node divides the list into 2 parts. We have to treat the left as well as the right part separately.
-> Set the middle element of the left part of the linked list as the left child of the root node.
-> Set the middle element of the right part of the linked list as the right child of the root node.
-> Recur until a single node is obtained in the left as well as the right parts of the lists and create 
separate nodes for them, respectively. 
-> In the last step, return the root node. 
*/

class Solution {
    TreeNode* createBST(ListNode* head, int size){
        if(size<=0) return NULL;
        if(size==1) return new TreeNode(head->val);
        ListNode* temp=head;
        int mid=size/2;
        while(mid--){
            temp=temp->next;
        }
        TreeNode* node=new TreeNode(temp->val,createBST(head,size/2),// Recur call for left subtree
        createBST(temp->next,size-size/2-1));// Recur call for right subtree
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        return createBST(head,size);
    }
};

int main()
{
    return 0;
}