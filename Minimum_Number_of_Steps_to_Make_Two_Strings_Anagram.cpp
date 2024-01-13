#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the minimum number of steps required to make two
strings `s` and `t` anagrams. We achieve this by using an array helper of
size 26 to count the occurrences of each character in both strings. The
first loop iterates through both strings simultaneously, incrementing
the `count` for characters in `t` and decrementing for characters in `s`.
The second loop calculates the total count of excess characters in `t`
compared to `s`, representing the minimum steps needed to transform `s`
into an anagram of `t`.
*/

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int helper[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            helper[t[i] - 'a']++;
            helper[s[i] - 'a']--;
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
            count += max(0, helper[i]);
        return count;
    }
};

int main()
{
    return 0;
}