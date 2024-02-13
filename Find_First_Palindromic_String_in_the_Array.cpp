#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We iterate through the string from both ends simultaneously, comparing
characters until reaching the middle. If any mismatch is encountered,
indicating non-palindromicity, we return false; otherwise, we return
true. In the main function, each word in the input vector is passed to
this helper function sequentially. Upon encountering the first palindrome,
the function returns that word; otherwise, we return an empty string if
no palindrome is found among the words.
*/

class Solution
{
    bool helper(string &s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

public:
    string firstPalindrome(vector<string> &words)
    {
        for (string s : words)
        {
            if (helper(s))
                return s;
        }
        return "";
    }
};

int main()
{
    return 0;
}