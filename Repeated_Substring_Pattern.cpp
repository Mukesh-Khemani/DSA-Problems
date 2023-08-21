#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we are given a string s, and we need to check if it can be
constructed by taking a substring of it and appending multiple copies of the
substring together. To solve this question efficiently, one needs to know
about the functions of string like 'substring' and 'find'.

APPROACH:
We are checking whether the original string s can be constructed by repeatedly
concatenating a non-empty substring of itself. If this is the case, we return
true; otherwise, false.
*/

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;
    }
};

int main()
{
    return 0;
}