#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The maximum time for information propagation depends on the time taken by each employee
and the hierarchy structure. We need to find the maximum time by considering the subordinates
of each employee.

APPROACH:
The solution uses a recursive approach to traverse the hierarchy and calculate the maximum time
required for information propagation. By starting from the head employee and recursively
considering the subordinates, it accumulates the maximum time along the hierarchy until reaching
the leaf employees.
*/

class Solution
{
    int helper(int headID, vector<int> &informTime,
               unordered_map<int, vector<int>> &map)
    {
        int maxTime = 0;
        if (map.find(headID) != map.end())
        {
            for (int i = 0; i < map[headID].size(); i++)
            {
                maxTime = max(maxTime, helper(map[headID][i], informTime, map));
            }
        }
        return maxTime + informTime[headID];
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager,
                     vector<int> &informTime)
    {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != (-1))
                map[manager[i]].push_back(i);
        }
        return helper(headID, informTime, map);
    }
};

int main()
{
    return 0;
}