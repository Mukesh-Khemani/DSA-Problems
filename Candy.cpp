#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to distribute candies to children with ratings such that
each child receives at least one candy, and a child with a higher rating
than their adjacent neighbor receives more candies. We do this by first
initializing each child with one candy and then performing two passes
through the ratings array: one from left to right and one from right to
left. In the first pass, we increase the number of candies for a child
if their rating is higher than the previous child. In the second pass,
we adjust the number of candies to ensure that the second condition is
met while maximizing the total number of candies distributed.
*/

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i],
                                 candies[i + 1] + 1);
        }
        int ans = 0;
        for (int candy : candies)
            ans += candy;
        return ans;
    }
};

int main()
{
    return 0;
}