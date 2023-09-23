#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the length of the longest string chain among a
given list of words. We begin by sorting the words based on their lengths.
Then, we iterate through the sorted list, and for each word, we systematically
check the longest chain it can form by removing one character at a time and
verifying if the resulting substring exists in the map. The map stores the
longest chain length for each word encountered so far. We update this map and
track the overall longest chain length encountered. Finally, we return the
maximum chain length found.
*/

class Solution
{
public:
    static bool compare(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), compare);
        map<string, int> map;
        int ans = 0;
        for (string word : words)
        {
            int longest = 0;
            for (int i = 0; i < word.length(); i++)
            {
                string sub = word;
                sub.erase(i, 1);
                longest = max(longest, map[sub] + 1);
            }
            map[word] = longest;
            ans = max(ans, longest);
        }
        return ans;
    }
};

int main()
{
    return 0;
}