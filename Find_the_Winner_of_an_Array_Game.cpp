#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The main intuition is to simulate a game where two players alternately
take turns, and the winner is the first player to achieve a winning
streak of k consecutive victories or reach the maximum element in the
array. So we initialize variables to track the current maximum and a
streak counter, then iterates through the array. We update the current
maximum and streak based on the comparison of the current and next elements.
If the streak reaches k or the current element becomes the maximum,
we return the winning element.
*/

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int maximum = arr[0];
        for (int i = 1; i < arr.size(); i++)
            maximum = max(maximum, arr[i]);
        int curr = arr[0];
        int streak = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (curr > arr[i])
                streak++;
            else
            {
                curr = arr[i];
                streak = 1;
            }
            if (streak == k or curr == maximum)
                return curr;
        }
        return -1;
    }
};

int main()
{
    return 0;
}