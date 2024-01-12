#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition is to determine if the first half of a given string `s` has the same
number of vowels as the second half. So we iterate through the first half of the
string, incrementing a count for each vowel encountered and decrementing it for each
vowel in the corresponding position of the second half. By employing a checker
function to identify vowels, we track the balance of vowels between the two halves.
The final check verifies if the count is zero, indicating an equal number of vowels
in both halves, and return a boolean result accordingly.
*/

class Solution
{
    bool checker(char c)
    {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U';
    }

public:
    bool halvesAreAlike(string s)
    {
        int firstHalf = 0;
        for (int i = 0; i < s.size() / 2; i++)
        {
            firstHalf += checker(s[i]) ? 1 : 0;
            firstHalf -= checker(s[s.size() - i - 1]) ? 1 : 0;
        }
        return firstHalf == 0;
    }
};

int main()
{
    return 0;
}