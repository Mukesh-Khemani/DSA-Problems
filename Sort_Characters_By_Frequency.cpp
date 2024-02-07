#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The solution aims to first count the frequency of each character in the input
string using a map. Then, we store these frequencies along with their
corresponding characters in a vector of pairs. By sorting this vector in
descending order based on frequency, we ensure that characters with higher
frequencies appear first. Finally, we construct the sorted string by appending
each character the number of times corresponding to its frequency in the
sorted vector.
*/

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<int, char>> helper;
        map<char, int> map;
        for (auto i : s)
            map[i]++;
        for (auto i : map)
            helper.push_back({i.second, i.first});
        sort(helper.begin(), helper.end(), greater<pair<int, char>>());

        string answer = "";
        for (auto i : helper)
        {
            while (i.first--)
                answer += i.second;
        }
        return answer;
    }
};

int main()
{
    return 0;
}