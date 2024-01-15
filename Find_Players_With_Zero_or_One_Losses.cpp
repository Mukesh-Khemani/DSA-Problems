#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to identify winners in a series of matches based on the provided input
vector of matches. We use an unordered map, `mp`, to count the number of losses for each
player. We iterate through the matches to update the loss count and categorize players
into two groups: those who did not lose (`didNotLose`) and those who lost once (`lostOnce`).
Players who did not lose are identified by checking the map, and if a winner is not found
in the loss count map, they are added to the `didNotLose` vector. Similarly, players who
lost once are determined by checking if the corresponding loss count is equal to 1, and
they are added to the `lostOnce` vector. Both vectors are then sorted, and we return a vector
of vectors containing these two groups of players.
*/

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < matches.size(); i++)
        {
            int lose = matches[i][1];
            mp[lose]++;
        }
        vector<int> didNotLose;
        vector<int> lostOnce;
        for (int i = 0; i < matches.size(); i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];
            if (mp.find(winner) == mp.end())
            {
                didNotLose.push_back(winner);
                mp[winner] = 2;
            }
            if (mp[loser] == 1)
                lostOnce.push_back(loser);
        }
        sort(didNotLose.begin(), didNotLose.end());
        sort(lostOnce.begin(), lostOnce.end());
        return {didNotLose, lostOnce};
    }
};

int main()
{
    return 0;
}