#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we need to find out the state of the asteroids after all collisions.
So for each asteroid, we check if it can collide destructively with the asteroids
currently in the stack. If the asteroid's size is negative (moving to the left) and
there are positive-sized asteroids in the stack (moving to the right), they will
collide destructively. In such cases, we pop the positive-sized asteroids from the
stack until no more collisions are possible or until the negative-sized asteroid is destroyed.
*/
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stack;
        for (int it : asteroids)
        {
            int flag = 1;
            while (!stack.empty() and (stack.top() > 0 and it < 0))
            {
                if (abs(stack.top()) < abs(it))
                {
                    stack.pop();
                    continue;
                }
                else if (abs(stack.top()) == abs(it))
                    stack.pop();
                flag = 0;
                break;
            }
            if (flag)
                stack.push(it);
        }
        vector<int> ans(stack.size());
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            ans[i] = stack.top();
            stack.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}