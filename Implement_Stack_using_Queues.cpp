#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
When a new element is pushed, it is added to one queue (q2) while all existing elements
are transferred from the other queue (q1) to the first queue in reverse order. This
ensures that the most recently pushed element is at the front of q1, simulating the
behavior of a stack. The pop operation simply involves removing the front element from q1,
while the top operation retrieves the front element without removing it.
*/

class MyStack
{
public:
    queue<int> q1, q2;
    MyStack()
    {
    }
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    return 0;
}