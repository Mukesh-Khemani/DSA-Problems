#include <bits/stdc++.h>
using namespace std;

/*
INTUITION + APPROACH:
The solution selects k candidates from both ends of the costs vector. It maintains
two priority queues, start and end, to store the costs from the start and end of
the vector. The algorithm iterates k times, selecting the candidate with the lowest
cost from either the start or end queue. This candidate is added to the total cost
res, and the corresponding queue is updated by removing the selected candidate. The
process continues until k candidates are selected. The intuition is to consider the
lowest-cost candidates from both ends to minimize the total cost.
*/

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> start, end;
        int i = 0, j = costs.size() - 1, count = 0;
        long long res = 0;
        while (count < k)
        {
            while (start.size() < candidates and i <= j)
                start.push(costs[i++]);
            while (end.size() < candidates and j >= i)
                end.push(costs[j--]);

            int startCandidatesCost = start.size() > 0 ? start.top() : INT_MAX;
            int endCandidatesCost = end.size() > 0 ? end.top() : INT_MAX;
            if (startCandidatesCost <= endCandidatesCost)
            {
                res += startCandidatesCost;
                start.pop();
            }
            else
            {
                res += endCandidatesCost;
                end.pop();
            }
            count++;
        }
        return res;
    }
};

int main()
{
    return 0;
}