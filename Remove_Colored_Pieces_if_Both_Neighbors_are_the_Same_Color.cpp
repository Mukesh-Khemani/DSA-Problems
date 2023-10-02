#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind this problem is to determine the winner of a game based
on a string of colors (denoted by 'A' and 'B'). So we iterate through the string
and identify sequences of three consecutive colors that are the same. For each
such sequence, we increment the respective player's score—Alice if the color is
'A' and Bob if the color is 'B'. The game's winner is determined by comparing the
scores, and we return true if Alice has scored at least one point more than Bob.
*/

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int Alice = 0;
        int Bob = 0;
        for (int i = 1; i < colors.size() - 1; i++)
        {
            if (colors[i - 1] == colors[i] and colors[i] == colors[i + 1])
            {
                colors[i] == 'A' ? Alice++ : Bob++;
            }
        }
        return Alice - Bob >= 1;
    }
};

int main()
{
    return 0;
}