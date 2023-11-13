#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to sort the vowels in a given string while maintaining the
order of non-vowel characters. We use an unordered map, `count`, to keep
track of the occurrences of each vowel in the input string. We iterate through
the string, incrementing the count of vowels in the map. The sorted order of
vowels is represented by the string `sortedVowel`. The algorithm then traverses
the input string again, appending non-vowel characters directly to the result
and, for each vowel, appends the next vowel in the sorted order while decrementing
its count in the map.
*/

class Solution
{
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' ||
               c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I';
    }

public:
    string sortVowels(string s)
    {
        unordered_map<char, int> count;
        for (char c : s)
        {
            if (isVowel(c))
                count[c]++;
        }
        string sortedVowel = "AEIOUaeiou";
        string ans;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!isVowel(s[i]))
                ans += s[i];
            else
            {
                while (count[sortedVowel[j]] == 0)
                    j++;
                ans += sortedVowel[j];
                count[sortedVowel[j]]--;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}