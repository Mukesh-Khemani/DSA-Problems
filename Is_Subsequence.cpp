#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is to determine if one string,
`s`, is a subsequence of another string, `t`, by comparing their
characters in a linear pass through `t`. We use two pointers, `i`
and `j`, to traverse the characters of `t` and `s`, respectively.
When a matching character is found, `j` is incremented, indicating
progress in finding `s` within `t`. If `j` reaches the length of `s`,
it means that all characters in `s` have been found in the same order
in `t`, and the function returns `true`, otherwise `false`.
*/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        while (i < t.size())
        {
            if (t[i] == s[j])
            {
                j++;
            }
            i++;
        }
        return j == s.size() ? true : false;
    }
};

int main()
{
    return 0;
}