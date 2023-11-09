#include <bits/stdc++.h>
using namespace std;

/*
The problem aims to calculate the number of homogenous substrings
in a given string `s`. A homogenous substring is defined as a
substring where all characters are the same. We iterate through the
string, maintaining a current streak length (`currStreak`) for
consecutive identical characters. For each character, if it is the
same as the previous one, the streak length is incremented; otherwise,
it is reset to 1. We accumulate the count of homogenous substrings by
adding the current streak length to the running total (`ans`), and the
result is returned.
*/

class Solution
{
public:
    int countHomogenous(string s)
    {
        int ans = 0;
        int currStreak = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0 or s[i] == s[i - 1])
                currStreak++;
            else
                currStreak = 1;
            ans = (ans + currStreak) % MOD;
        }
        return ans;
    }
};

int main()
{
    return 0;
}