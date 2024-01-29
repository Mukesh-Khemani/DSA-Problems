#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The `MyQueue` class implements a queue using two stacks. In the `push` operation,
elements are pushed onto `s1`, the primary stack. For `pop` and `peek` operations,
elements are transferred from `s1` to `s2`, reversing their order, allowing the
oldest element to be accessed first. This approach ensures FIFO (First-In-First-Out)
order in the queue. The `empty` function checks if both stacks are empty, indicating
whether the queue is empty or not.
*/

class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue() {}
    void push(int x)
    {
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }
    int pop()
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    int peek()
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    return 0;
}