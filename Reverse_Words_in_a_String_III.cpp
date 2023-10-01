#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind this problem is to reverse the words in a given string.
We use a stack to collect characters of each word while iterating through
the string. When a space character or the end of the string is encountered,
the characters are popped from the stack and appended to the result string.
We ensure that a space is added after each word except for the last one. This
process effectively reverses the order of words in the original string.
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        string result = "";
        stack<char> stack;
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] == 32 or i == s.size())
            {
                while (!stack.empty())
                {
                    result += stack.top();
                    stack.pop();
                }
                if (i != s.size())
                    result += " ";
            }
            else
                stack.push(s[i]);
        }
        return result;
    }
};

int main()
{
    return 0;
}