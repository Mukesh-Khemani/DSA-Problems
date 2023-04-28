#include <bits/stdc++.h>
using namespace std;
/*INTUITION:
In this question, the aim was to find number of distinct groups of strings that are similar. Two strings are said to be similar
if they are exactly same or one can be obtained by swapping any 2 characters of the other string. This hints towards DFS.
SOLUTION:
The solution uses DFS to traverse of the array meanwhile maintaining a visited array. If any element of
the array is unvisited, we perform dfs and compare this element to all the other unvisited elements of the array.
Logic: As the array contains all the anagrams of the string, two strings are said to be similar if and only if
they have 2 or 0 unequal characters(depicted by 'count' in the 'isSimilar' function).
*/
class Solution
{
    bool isSimilar(string s1, string s2)
    {
        int count = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                count++;
            if (count > 2)
                return false;
        }
        return count == 0 || count == 2;
    }
    void dfs(vector<string> &strs, int curr, vector<bool> &visited)
    {
        if (visited[curr])
            return;
        visited[curr] = true;
        for (int i = 0; i < strs.size(); i++)
        {
            if (isSimilar(strs[curr], strs[i]))
            {
                dfs(strs, i, visited);
            }
        }
    }

public:
    int numSimilarGroups(vector<string> &strs)
    {
        if (strs.size() == 0)
            return 0;
        int result = 0;
        int n = strs.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(strs, i, visited);
                result++;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}