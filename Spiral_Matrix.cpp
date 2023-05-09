#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The most optimal solution to this problem is the most simple and the most basic.
We need to traverse the entire matrix in a spiral order. Starting from the top-left
to the bottom-right and then the vice-versa.

Solution:
-> We need to iterate through the matrix until all the elements of the matrix are
appended to the array. For this, we use the concept of nested loops.
1) The first loop traverses from the top-left corner to the top-right corner,
incrementing the top at the end.
2) The second loop traverses from the top-right corner to the bottom-right corner,
decrementing the right at the end.
3) The third loop traverses from the bottom-right corner to the bottom-left corner,
decrementing the bottom at the end.
4) The last loop traverses from the bottom-left corner to the top-left corner,
incrementing the left at the end.

-> If at any instance, the size of the array is equal than the size of the matrix,
we return the resultant array.
*/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, left = 0, right = m - 1, bottom = n - 1;
        vector<int> v;
        while (v.size() != m * n)
        {
            for (int i = left; v.size() != m * n and i <= right; i++)
            {
                v.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; v.size() != m * n and i <= bottom; i++)
            {
                v.push_back(matrix[i][right]);
            }
            right--;
            for (int i = right; v.size() != m * n and i >= left; i--)
            {
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
            for (int i = bottom; v.size() != m * n and i >= top; i--)
            {
                v.push_back(matrix[i][left]);
            }
            left++;
        }
        return v;
    }
};

int main()
{
    return 0;
}