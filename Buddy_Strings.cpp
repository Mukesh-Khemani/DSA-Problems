#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given problem wants us to check if two strings, s and goal, are buddy strings
or not. Buddy strings are defined as two strings that can be obtained by swapping
exactly two characters in one of the strings.

APPROACH:
In the given solution, we check if two strings, s and goal, are buddy strings or not. We
first handle the case where s and goal are identical, checking for duplicate characters.
Then, we find the differing indices between s and goal. If there are exactly two differing
indices and swapping the characters at those indices results in goal, the strings are buddy
strings.
*/

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        if (s == goal)
        {
            vector<int> freq(26, 0);
            for (auto &character : s)
            {
                freq[character - 'a'] += 1;
                if (freq[character - 'a'] == 2)
                    return true;
            }
            return false;
        }
        int index1 = -1;
        int index2 = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
            {
                if (index1 == -1)
                    index1 = i;
                else if (index2 == -1)
                    index2 = i;
                else
                    return false;
            }
        }
        if (index2 == -1)
            return false;
        return s[index1] == goal[index2] and s[index2] == goal[index1];
    }
};

int main()
{
    return 0;
}