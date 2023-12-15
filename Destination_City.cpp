#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the destination city in a list of paths
represented by a vector of vectors. We use an unordered set, `outgoingPath`,
to store all the cities that have outgoing paths. In the first loop, we
populate the set with the starting cities of the paths. Then, in the second
loop, we iterate through the paths again, checking for the destination city
(`curr`). If the destination city is not found in the set of outgoing paths,
it implies that it is the final destination, and the function returns that city.
*/

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> outgoingPath;
        for (int i = 0; i < paths.size(); i++)
            outgoingPath.insert(paths[i][0]);
        for (int i = 0; i < paths.size(); i++)
        {
            string curr = paths[i][1];
            if (outgoingPath.find(curr) == outgoingPath.end())
                return curr;
        }
        return "";
    }
};

int main()
{
    return 0;
}