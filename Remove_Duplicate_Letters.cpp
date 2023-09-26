#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is to remove duplicate letters from a given
string while maintaining the order of the remaining characters and selecting
the smallest lexicographically possible result. To achieve this, we use a
stack to keep track of characters and a set to keep track of characters that
have been seen. We also maintain a map to store the last occurrence index of
each character in the input string. We iterate through the input string, and
for each character, we check whether it should be added to the result or not
by comparing it with the characters in the stack. If the character is smaller
and there are more occurrences of it later in the string, we remove characters
from the stack until it can safely add the current character. Finally, we
construct the result string by popping characters from the stack in reverse order.
*/

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> stack;
        set<char> seen;
        map<char, int> last_occ;
        for (int i = 0; i < s.size(); i++)
            last_occ[s[i]] = i;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (seen.find(c) == seen.end())
            {
                while (!stack.empty() and c < stack.top() and
                       i < last_occ[stack.top()])
                {
                    seen.erase(stack.top());
                    stack.pop();
                }
                seen.insert(c);
                stack.push(c);
            }
        }
        string res = "";
        while (!stack.empty())
        {
            res = stack.top() + res;
            stack.pop();
        }
        return res;
    }
};

int main()
{
    return 0;
}