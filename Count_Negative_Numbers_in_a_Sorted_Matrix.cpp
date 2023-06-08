#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is that by starting from the bottom-left corner
of the grid, we can efficiently traverse through the grid and count the negative
numbers. Since the grid is sorted, we know that once we encounter a negative number,
all the remaining elements in that row will also be negative. Therefore, we can increment
the count by the number of remaining columns in that row. By moving upward in the grid
and skipping unnecessary elements, we can avoid counting the positive numbers and optimize
the counting process.

NOTE: We are mainly taking advantage of the condition that the matrix is sorted in a
descending order. This means that the count of the negative numbers in the array at the ith
index will be less than or equal to the count of the negative numbers of the array at the
(i+1)th index.

*/

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int answer = 0;
        int row = grid.size() - 1;
        int col = 0;
        int totalColumns = grid[0].size();
        while (row >= 0 and col < totalColumns)
        {
            if (grid[row][col] < 0)
            {
                answer += totalColumns - col;
                row--;
            }
            else
            {
                col++;
            }
        }
        return answer;
    }
};

int main()
{
    return 0;
}