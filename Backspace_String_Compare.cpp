#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We employ two stacks to simulate the effect of backspaces while processing
each character in the input strings. After processing, we compare the
resulting stacks to determine equality, handling scenarios where one stack
might be popped when empty. The use of stacks allows for efficient backspace
handling and simplifies the comparison process.
*/

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<int> one, two;
        for (char c : s)
        {
            if (c == '#')
            {
                if (!one.empty())
                    one.pop();
            }
            else
                one.push(c);
        }
        for (char c : t)
        {
            if (c == '#')
            {
                if (!two.empty())
                    two.pop();
            }
            else
                two.push(c);
        }
        if (one.size() != two.size())
            return false;
        while (!one.empty())
        {
            if (two.empty() or one.top() != two.top())
                return false;
            one.pop();
            two.pop();
        }
        return one.empty() and two.empty();
    }
};

int main()
{
    return 0;
}