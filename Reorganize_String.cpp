#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We start by identifying the character with the maximum frequency and store its index.
If this maximum frequency is greater than half the length of the input string, a valid
reorganization isn't possible, and an empty string is returned. Otherwise, we construct
the reorganized string by alternating between inserting the character with the maximum
frequency (ensuring no adjacent duplicates) and distributing the remaining characters.
By following this alternating insertion pattern, we create a reorganized string that
meets the specified criteria of non-adjacent identical characters.
*/

class Solution
{
public:
    string reorganizeString(string s)
    {
        vector<int> count(26, 0);
        for (char c : s)
            count[c - 'a']++;
        int maxCount = 0, letter = 0;
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] > maxCount)
            {
                maxCount = count[i];
                letter = i;
            }
        }
        if (maxCount > (s.length() + 1) / 2)
            return "";
        string ans = s;
        int index = 0;
        while (count[letter] != 0)
        {
            ans[index] = char(letter + 'a');
            index += 2;
            count[letter]--;
        }
        for (int i = 0; i < count.size(); i++)
        {
            while (count[i] > 0)
            {
                if (index >= s.size())
                    index = 1;
                ans[index] = char(i + 'a');
                index += 2;
                count[i]--;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}