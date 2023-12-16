#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to determine whether two strings, `s` and `t`, are anagrams
of each other. We use an integer array `map` of size 26 to represent the
frequency of each character in the English alphabet. We first check if the
lengths of the two strings are unequal, in which case they cannot be anagrams,
and returns false. We then iterate through both strings, incrementing the
frequency for characters in `s` and decrementing for characters in `t`. Finally,
we check if the frequency array is entirely zero, indicating that the strings
are anagrams.
*/

class Solution
{
    int map[26] = {0};

public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            map[index]++;
            index = t[i] - 'a';
            map[index]--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (map[i])
                return false;
        }

        return true;
    }
};

int main()
{
    return 0;
}