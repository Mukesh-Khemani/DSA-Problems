#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The key is to check that the parentheses are matched in correct order or not.
That is, each closing parentheses must match the most recently opened opening parentheses.
For example, ')' should be matched with '(', ']' with '[' and '}' with '{'.
Solution:
-> We are using a stack to store the opening parentheses in the input string.
-> Whenever we encounter a closing parentheses, we check whether the top element of the
stack matches the corresponding opening parentheses.
-> If it does, we pop the element from the stack and continue.
-> If it doesn't, we can return False immediately.
-> In the end, if the stack is empty, the given string is valid. Else not.
*/
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> S;
        if (s.length() % 2 == 1 or s[0] == ')' or s[0] == ']' or s[0] == '}')
        {
            return 0;
        }
        for (char c : s)
        {
            if (c == '(' or c == '{' or c == '[')
                S.push(c);
            else
            {
                if (S.empty() or (c == ')' and S.top() != '(') or (c == '}' and S.top() != '{') or (c == ']' and S.top() != '['))
                    return 0;
                S.pop();
            }
        }
        return S.empty();
    }
};

int main()
{
    return 0;
}