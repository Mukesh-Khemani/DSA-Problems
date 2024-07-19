#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind this solution is to find a "lucky number" in a matrix, which is defined as an
element that is the lowest in its row but the highest in its column. To accomplish this, we iterate
through each row to find the minimum value, and then keep track of the maximum of these row minimums.
We then iterate through each column to find the maximum value in each column while keeping track of
the minimum of these column maximums. If the maximum of the row minimums equals the minimum of the
column maximums, the value is returned as a lucky number. If there is no such number, an empty list
is returned.
*/

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();

        int maxRowMin = INT_MIN;
        for (int i = 0; i < rows; i++)
        {
            int rowMin = INT_MAX;
            for (int j = 0; j < cols; j++)
            {
                rowMin = min(rowMin, matrix[i][j]);
            }
            maxRowMin = max(maxRowMin, rowMin);
        }
        int minColMax = INT_MAX;
        for (int j = 0; j < cols; j++)
        {
            int colMax = INT_MIN;
            for (int i = 0; i < rows; i++)
            {
                colMax = max(colMax, matrix[i][j]);
            }
            minColMax = min(minColMax, colMax);
        }
        if (maxRowMin == minColMax)
        {
            return {maxRowMin};
        }
        return {};
    }
};

int main()
{
    return 0;
}