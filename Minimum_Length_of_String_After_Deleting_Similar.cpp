#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the minimum length of a non-empty string by removing
characters from its ends until all remaining characters are the same. We employ
a two-pointer approach to iteratively check and remove characters from both
ends of the string. The 'begin' pointer starts from the beginning of the string,
the 'end' pointer starts from the end of the string, and they converge towards
each other while removing matching characters. This process continues until the
characters at 'begin' and 'end' are no longer the same or until the two pointers
meet. We then calculate and return the length of the substring between 'begin'
and 'end', inclusive.
*/

class Solution
{
public:
    int minimumLength(string s)
    {
        int begin = 0;
        int end = s.length() - 1;
        while (begin < end and s[begin] == s[end])
        {
            char c = s[begin];
            while (begin <= end and s[begin] == c)
                begin++;
            while (end > begin and s[end] == c)
                end--;
        }
        return end - begin + 1;
    }
};

int main()
{
    return 0;
}