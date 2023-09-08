#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
This problem defines a `generate` function that constructs Pascal's
Triangle up to a specified number of rows, given as `Rows`. So we use
a vector of vectors, `result`, to store the triangle's rows. We iterate
through each row, starting from the first row (row index 0), and within
each row, we calculate the values based on the previous row's values
using the binomial coefficient formula (n choose k). The inner loop runs
from `1` to `i-1`, where `i` is the current row number. The calculated
values are added to the `row` vector, and once the row is complete, it's
pushed into the `result` vector.
*/

class Solution
{
public:
    vector<vector<int>> generate(int Rows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < Rows; i++)
        {
            vector<int> row;
            row.push_back(1);
            for (int j = 1; j < i; j++)
            {
                int x = result[i - 1][j - 1] + result[i - 1][j];
                row.push_back(x);
            }
            if (i)
                row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};

int main()
{
    return 0;
}