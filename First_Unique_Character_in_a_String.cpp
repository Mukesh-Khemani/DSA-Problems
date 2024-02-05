#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind this solution is to iterate through the given string
and count the occurrences of each character using a map. After counting,
another iteration is performed to find the index of the first character
with a count of 1, indicating uniqueness. If such a character is found,
its index is returned; otherwise, -1 is returned, indicating that no
unique character exists in the string.
*/

class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> count;
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i]]++;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    return 0;
}