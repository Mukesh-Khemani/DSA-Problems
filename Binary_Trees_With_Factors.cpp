#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The aim of the problem is to count the number of unique binary trees that can
be formed using elements from a sorted array arr. We use dynamic programming
and a set to efficiently compute the count of binary trees for each element.
We iterate through pairs of elements, checking their divisibility relationship,
and calculates the count of binary trees by multiplying the counts of the divisors.
The final result is obtained by summing up all the counts in the dynamic programming
map. The set s ensures quick lookup of elements, and the modular arithmetic prevents
integer overflow, making the solution robust for various inputs.
*/

const int MOD = 1e9 + 7;
class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        set<int> s(arr.begin(), arr.end());
        map<int, int> dp;
        for (int it : arr)
            dp[it] = 1;
        for (int i : arr)
        {
            for (int j : arr)
            {
                if (j > sqrt(i))
                    break;
                if (i % j == 0 and s.find(i / j) != s.end())
                {
                    long long temp = (long long)dp[j] * dp[i / j];
                    if (i / j == j)
                        dp[i] = (dp[i] + temp) % MOD;
                    else
                        dp[i] = (dp[i] + temp * 2) % MOD;
                }
            }
        }
        int result = 0;
        for (auto &[_, val] : dp)
            result = (result + val) % MOD;
        return result;
    }
};

int main()
{
    return 0;
}