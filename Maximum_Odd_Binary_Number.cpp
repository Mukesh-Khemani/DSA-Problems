#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the maximum odd binary number that can be formed
by manipulating the input string `s`. We first count the number of '1's in
the input string to determine the length of the resulting binary number.
Then, we construct the maximum odd binary number by appending '1's until
there are 'ones - 1' digits, followed by a '0', and finally, appending a
'1' to ensure the number remains odd.
*/

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int n = s.length();
        int ones = 0;
        for (char &c : s)
            ones += c == '1' ? 1 : 0;
        string ans = "";
        for (int i = 0; i < n - 1; i++)
        {
            if (i < ones - 1)
                ans += "1";
            else
                ans += "0";
        }
        ans += "1";
        return ans;
    }
};

int main()
{
    return 0;
}