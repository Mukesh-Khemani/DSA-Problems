#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this question, we had to design an algorithm that collects daily price quotes for some
stock and returns the span of that stock's price for the current day. The span of the
stock's price in one day is the maximum number of consecutive days (starting from that day
and going backward) for which the stock price was less than or equal to the price of that day.
For this we have multiple approaches:

-> Approach 1:
Store all the daily stock prices in an array and find the number of days
while traversing from the last and return the answer in the end.

-> Approach 2:
The above approach traverses through the same elements for calculating
the span for each stock price. This makes it redundant and more time taking.
So lets use the concept of Monotonic stack which stores the elements in
descending order along with the record of the span of the last stock price
as well. This makes the time complexity O(1).

*/

class StockSpanner
{
public:
    // Initializes the object of the class.
    StockSpanner()
    {
    }

    stack<pair<int, int>> s;
    int next(int price)
    {
        int res = 1;
        while (!s.empty() and price >= s.top().first)
        {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

int main()
{
    return 0;
}