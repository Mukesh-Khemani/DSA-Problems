#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The LRUCache class uses a doubly linked list and a hashmap to implement the LRU
(Least Recently Used) caching strategy. It maintains a linked list to track the
order of key-value pairs based on their usage, with the head node representing
the most recently used item. Each item is stored in a hashmap for efficient lookup.
When accessing an item, it is moved to the front of the linked list. When adding a
new item, it is inserted at the front, and if the cache is full, the least recently
used item is removed.
*/

class LRUCache
{
    class node
    {
    public:
        int val;
        int key;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node *> m;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
    }
    void deleteNode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *resNode = m[key];
            int res = resNode->val;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            node *delNode = m[key];
            m.erase(key);
            deleteNode(delNode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        m[key] = head->next;
    }
};

int main()
{
    return 0;
}