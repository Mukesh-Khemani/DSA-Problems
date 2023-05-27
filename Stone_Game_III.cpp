#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem involves a game where Alice and Bob take turns picking stones from a given vector
of stone values. Each player plays to win. The helper function calculate the maximum score difference.
Then, accordingly the winner of the game is decided.
EXPLANATION:
At each index i, Alice has three options:
- Alice picks the current stone only (s[i]) and calculates the score difference by subtracting the
score of the remaining game (recursive call to helper(s, i+1)).
- Alice picks the current stone (s[i]) and the next stone (s[i+1]), and calculates the score difference
by subtracting the score of the remaining game (recursive call to helper(s, i+2)).
- Alice picks the current stone (s[i]), the next stone (s[i+1]), and the stone after the next (s[i+2]),
and calculates the score difference by subtracting the score of the remaining game (recursive call to
helper(s, i+3)).
*/
class Solution
{
    int dp[50001];
    int helper(vector<int> &s, int i)
    {
        if (i > s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        else
        {
            int ans = INT_MIN;
            ans = max(ans, s[i] - helper(s, i + 1));
            if (i + 1 < s.size())
                ans = max(ans, s[i] + s[i + 1] - helper(s, i + 2));
            if (i + 2 < s.size())
                ans = max(ans, s[i] + s[i + 1] + s[i + 2] - helper(s, i + 3));
            return dp[i] = ans;
        }
    }

public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        for (int i = 0; i < stoneValue.size(); i++)
            dp[i] = -1;
        int Alice = helper(stoneValue, 0);
        if (Alice > 0)
            return "Alice";
        else if (Alice < 0)
            return "Bob";
        return "Tie";
    }
};

int main()
{
    return 0;
}