#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION:
In this question, we keep on iterating and adding the current
element of both the strings to a resultant string until both
the strings are exhausted.
*/

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string s;
        for (int i = 0; i <= word1.size() or i <= word2.size(); i++)
        {
            if (i < word1.size())
                s += word1[i];
            if (i < word2.size())
                s += word2[i];
        }
        return s;
    }
};

int main()
{
    return 0;
}