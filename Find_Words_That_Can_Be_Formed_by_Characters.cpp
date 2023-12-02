#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
This problem aims to count the total length of words in the given vector `words`
that can be formed using the characters from the string `chars`. We start by
creating an array `v` to store the frequency of each character in `chars`. Then,
for each word in the vector, we create a local array `count` to track the frequency
of each character in the word. We compare the counts of each character in `count`
with their respective counts in `v`. If at any point, the count of a character in
the word exceeds its count in `chars`, the word is deemed not formable, and the
process moves on to the next word. If a word is deemed "good" (i.e., can be formed
using the characters in `chars`), its length is added to the running total (`ans`).
The final result is the sum of the lengths of all "good" words in the vector.
*/

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> v(26, 0);
        for (char c : chars)
        {
            v[c - 'a']++;
        }

        int ans = 0;
        for (string word : words)
        {
            vector<int> count(26, 0);
            for (char c : word)
            {
                count[c - 'a']++;
            }

            bool isGood = true;
            for (int i = 0; i < 26; i++)
            {
                if (v[i] < count[i])
                {
                    isGood = false;
                    break;
                }
            }

            if (isGood)
            {
                ans += word.size();
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}