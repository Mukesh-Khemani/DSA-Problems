#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The main aim of this problem is to calculate the maximum number of
monsters a player can eliminate before any of them reaches the player's
location. So we use a priority queue to store the time required for each
monster to reach the player, calculated as the distance divided by the
monster's speed. The priority queue is organized in ascending order of
time. We iterate through the priority queue, popping monsters and
incrementing the count until the time taken by a monster exceeds the count
of eliminated monsters (ans). The final count represents the maximum number
of monsters that can be eliminated before any reaches the player.
*/

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        priority_queue<float, vector<float>, greater<float>> pq;
        for (int i = 0; i < dist.size(); i++)
            pq.push((float)dist[i] / speed[i]);
        int ans = 0;
        while (!pq.empty())
        {
            if (pq.top() <= ans)
                break;
            ans++;
            pq.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}