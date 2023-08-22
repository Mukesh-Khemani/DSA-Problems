#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the given problem, we are given an integer columnNumber, and we need
to return its corresponding column title as it appears in an Excel sheet.
We achieve this by iteratively mapping remainders of the column number
divided by 26 to ASCII values representing uppercase letters and then
adjusting the number for the next digit, we effectively reconstruct the
title.
*/

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber > 0)
        {
            columnNumber--;
            ans += (columnNumber % 26 + 65);
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    return 0;
}