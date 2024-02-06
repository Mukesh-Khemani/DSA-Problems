#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We iterate through the input vector of strings, sorting each string to
obtain a unique key representing its sorted characters. If the key does
not exist in the map, a new entry is created with the key and the current
string. Otherwise, the string is added to the existing entry corresponding
to the key. Finally, we construct the result vector by iterating through
the map and appending the values (groups of anagrams) to it.
*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> anagram;
        for (string &i : strs)
        {
            string key = i;
            sort(key.begin(), key.end());
            if (anagram.find(key) == anagram.end())
                anagram[key] = {i};
            else
                anagram[key].push_back(i);
        }
        vector<vector<string>> result;
        for (auto &group : anagram)
            result.push_back(group.second);
        return result;
    }
};

int main()
{
    return 0;
}