#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the minimum number of character deletions
required to make the frequency of each character in the given string
distinct. We do this by first counting the frequency of each character
in the string and then iterating through the frequencies. If a frequency
is already in use, we decrement the frequency until we find an unused one
while counting the deletions. The intuition is that by ensuring that no
two characters have the same frequency, we minimize the deletions needed
to achieve distinct frequencies.
*/

class Solution
{
public:
    int minDeletions(string s)
    {
        map<char, int> count;
        int ans = 0;
        set<int> unique;
        for (char c : s)
            count[c]++;
        for (auto &index : count)
        {
            int freq = index.second;
            while (freq > 0 and unique.find(freq) != unique.end())
            {
                freq--;
                ans++;
            }
            unique.insert(freq);
        }
        return ans;
    }
};

int main()
{
    return 0;
}