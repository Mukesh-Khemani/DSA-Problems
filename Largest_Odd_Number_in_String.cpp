#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the largest odd number within a given string `num`.
We iteratively check the digits of the number from right to left, and upon
encountering the first odd digit, we return a substring containing all
digits to its left. This ensures that the returned substring represents the
largest odd number possible. If no odd digit is found, we return an empty string.
*/

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int size = num.size();
        while (size--)
        {
            if (num[size] % 2)
                return num.substr(0, size + 1);
        }
        return "";
    }
};

int main()
{
    return 0;
}