#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to count the number of "special" elements in a binary matrix.
An element is considered special if it is the only one in its `row` and `column`
with a value of 1. We iterate through the matrix twice—first to count the number
of 1s in each row and column using the row and col vectors, and then to identify
and count the special elements. By checking for rows and columns with only one 1,
we effectively determine the number of special elements in the matrix.
*/

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (mat[r][c])
                {
                    row[r]++;
                    col[c]++;
                }
            }
        }

        int ans = 0;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (mat[r][c])
                {
                    if (row[r] == 1 && col[c] == 1)
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}