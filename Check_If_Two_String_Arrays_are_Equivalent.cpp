#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We iterate through the arrays simultaneously, concatenating the strings from
each array into two separate strings, `firstWord` and `secondWord`. The loop
continues until it reaches the end of both arrays. Finally, we return `true`
if the concatenated strings are equal and `false` otherwise. The intuition
behind this approach is to compare the overall concatenated representation
of the strings in both arrays, disregarding the individual elements' order
or specific array structure.
*/

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string firstWord = "", secondWord = "";
        int i = 0;
        while (i < word1.size() or i < word2.size())
        {
            if (i < word1.size())
                firstWord += word1[i];
            if (i < word2.size())
                secondWord += word2[i];
            i++;
        }
        return firstWord == secondWord;
    }
};

int main()
{
    return 0;
}