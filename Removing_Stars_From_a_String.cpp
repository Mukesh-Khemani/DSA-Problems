#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION:
In this question, we take a string 'str' and traverse the input string.
If we find a star ('*'), we remove the last character from the string 'str'.
Else we keep on adding the characters to the string 'str'.
*/

class Solution
{
public:
    string removeStars(string s)
    {
        string str;
        for (char i : s)
        {
            if (i == '*')
            {
                str.pop_back();
            }
            else
            {
                str += i;
            }
        }
        return str;
    }
};

int main()
{
    return 0;
}