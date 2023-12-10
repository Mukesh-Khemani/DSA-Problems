#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to compute the transpose of a given matrix, swapping
its rows and columns. We initialize a new matrix ans with dimensions
reversed (columns become rows and vice versa). We then iterate through
the original matrix, assigning the values from each row to the
corresponding column in the transposed matrix.
*/

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ans(col, vector<int>(row, 0));
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
                ans[i][j] = matrix[j][i];
        }
        return ans;
    }
};

int main()
{
    return 0;
}