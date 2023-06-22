#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The goal is to calculate the maximum profit that can be earned by completing as
many transactions as we like.

APPROACH:
So we use a dynamic programming approach to maximize profit in stock trading.
We keep track of the current buying and selling situations and updates them
based on the prices and transaction fee. By considering the maximum potential
profit at each step, we can efficiently compute the maximum profit achievable.
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int currBuy = INT_MIN, currSell = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            currBuy = max(currBuy, currSell - prices[i]);
            currSell = max(currSell, currBuy + prices[i] - fee);
        }
        return currSell;
    }
};

int main()
{
    return 0;
}