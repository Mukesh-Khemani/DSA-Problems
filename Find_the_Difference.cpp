#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is to find the extra character in string
`t` compared to string `s` by leveraging the differences in the ASCII
values of their characters. We iterate through both strings, accumulating
the ASCII values of their characters in the `sum` variable. By subtracting
the ASCII values of characters in `s` from those in `t`, we effectively
isolate the extra character, as we contribute to the difference in `sum`.
*/

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int sum = 0;
        for (auto &c : t)
            sum += c;
        for (auto &c : s)
            sum -= c;
        return char(sum);
    }
};

int main()
{
    return 0;
}