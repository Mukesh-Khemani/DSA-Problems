#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given code aims to the evaluation of Reverse Polish Notation (RPN) expressions
using a stack data structure. So we iterate through the tokens representing numbers
and operators. When encountering a number, it is pushed onto the stack. For operators,
the top two numbers are popped from the stack, the operation is performed, and the
result is pushed back onto the stack. Finally, the result remaining on the stack after
processing all tokens is returned as the evaluation result.
*/

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (const string &token : tokens)
        {
            if (token.size() > 1 or isdigit(token[0]))
            {
                s.push(stoi(token));
            }
            else
            {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();

                switch (token[0])
                {
                case '+':
                    s.push(first + second);
                    break;
                case '-':
                    s.push(first - second);
                    break;
                case '*':
                    s.push(first * second);
                    break;
                case '/':
                    s.push(first / second);
                    break;
                }
            }
        }
        return s.top();
    }
};

int main()
{
    return 0;
}