#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to calculate the total number of beams formed by counting
the occurrences of '1' in each string of a given vector `bank`. We iterate
through the strings, tracking the previous count of '1' (initialized as `prev`)
and the total number of beams (initialized as `ans`). For each string, we
count the occurrences of '1' and multiplies it by the previous count, adding
this product to the total number of beams. This process ensures that beams are
formed by connecting '1's across different strings.
*/

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int prev = 0, ans = 0;
        for (string s : bank)
        {
            int count = 0;
            for (char c : s)
            {
                if (c == '1')
                    count++;
            }
            if (count)
            {
                ans += (prev * count);
                prev = count;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}