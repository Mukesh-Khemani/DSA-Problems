#include <bits/stdc++.h>
using namespace std;

/*
INTUITION;
The problem aims to find the largest three-digit integer within the given
string `num` that has the same digit repeated three times consecutively.
We iterate through the string, identifying instances where a digit is
repeated three times in a row. The maximum of such digits is stored, and
the function returns a string containing three instances of the maximum
digit found. If no such digit is found, an empty string is returned.
*/

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        char max_Digit = '\0';
        for (int i = 0; i <= num.size() - 3; i++)
        {
            if (num[i] == num[i + 1] and num[i] == num[i + 2])
                max_Digit = max(max_Digit, num[i]);
        }
        return max_Digit == '\0' ? "" : string(3, max_Digit);
    }
};

int main()
{
    return 0;
}