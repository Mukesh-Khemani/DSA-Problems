#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We have a task of justifying a list of words into lines of equal width while adhering
to a specified maximum width. So we iterate through the words, progressively building
lines and calculating the total length of characters in the current line. When the
addition of a new word would exceed the maximum width, we distribute spaces evenly
between words to achieve the target width. The last line is handled separately, being
left-aligned with extra spaces added to the right.
*/

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        vector<string> current;
        int numLen = 0;
        for (string word : words)
        {
            if (word.size() + current.size() + numLen > maxWidth)
            {
                for (int i = 0; i < maxWidth - numLen; i++)
                {
                    current[i % (current.size() - 1 ? current.size() - 1 : 1)] += ' ';
                }
                result.push_back("");
                for (string s : current)
                    result.back() += s;
                current.clear();
                numLen = 0;
            }
            current.push_back(word);
            numLen += word.size();
        }
        string lastLine = "";
        for (string s : current)
            lastLine += s + ' ';
        lastLine = lastLine.substr(0, lastLine.size() - 1);
        while (lastLine.size() < maxWidth)
            lastLine += ' ';
        result.push_back(lastLine);
        return result;
    }
};

int main()
{
    return 0;
}