#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the given problem, we implement a dynamic programming solution to count the
number of strings of length `n` that can be formed using vowels (a, e, i, o, u)
while satisfying specific conditions. We use five variables (a, e, i, o, u) to
represent the count of strings ending with each vowel. We iteratively calculate
the count of strings for each vowel, considering the allowed transitions between
vowels based on given conditions. The loop runs n-1 times, updating the counts
at each step. The final result is obtained by summing up the counts for all vowels
and taking the result modulo 1e9+7 to prevent integer overflow.
*/

const int MOD = 1e9 + 7;
class Solution
{
public:
    int countVowelPermutation(int n)
    {
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int j = 1; j < n; j++)
        {
            long long new_a = e;
            long long new_e = (a + i) % MOD;
            long long new_i = (a + e + o + u) % MOD;
            long long new_o = (i + u) % MOD;
            long long new_u = a;
            a = new_a, e = new_e, i = new_i, o = new_o, u = new_u;
        }
        return (a + e + i + o + u) % MOD;
    }
};

int main()
{
    return 0;
}