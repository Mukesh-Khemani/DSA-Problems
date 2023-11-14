#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to calculate the count of distinct palindromic subsequences formed
by characters in a given string. We initialize two vectors, first and last, to store
the first and last occurrences of each character in the alphabet. We then iterate
through the string, updating these vectors accordingly. Subsequently, we calculate
the count of distinct characters between the first and last occurrences of each
character and accumulate these counts for all characters. The result represents the
total count of palindromic subsequences.


*/

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<int> first = vector(26, -1);
        vector<int> last = vector(26, -1);
        for (int i = 0; i < s.size(); i++)
        {
            int curr = s[i] - 'a';
            if (first[curr] == -1)
                first[curr] = i;
            last[curr] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (first[i] == -1)
                continue;
            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; j++)
                between.insert(s[j]);
            ans += between.size();
        }
        return ans;
    }
};

int main()
{
    return 0;
}