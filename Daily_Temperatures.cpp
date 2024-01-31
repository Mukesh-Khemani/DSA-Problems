#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to calculate the number of days until the next warmer temperature for
each day in the input array of temperatures. We use a stack to keep track of indices
corresponding to temperatures for which a warmer temperature is yet to be found. While
iterating through the temperatures, we check if the current temperature is warmer than
the temperature corresponding to the index at the top of the stack. If so, we calculate
the number of days until the next warmer temperature by subtracting the current index
from the index at the top of the stack, updating the results array accordingly.
*/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> results(temperatures.size());
        stack<int> helper;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!helper.empty() and temperatures[helper.top()] < temperatures[i])
            {
                results[helper.top()] = i - helper.top();
                helper.pop();
            }
            helper.push(i);
        }
        return results;
    }
};

int main()
{
    return 0;
}