#include <bits/stdc++.h>
using namespace std;

/*
STEP BY STEP EXPLANATION:
The given code is used to generate a matrix of size n by n, where n is a positive integer.
The generated matrix follows a specific pattern: starting from the top-left corner, the
elements of the matrix are filled in a clockwise spiral order until the center is reached.
Here's the intuition behind the code:
1)Initialize the 2D vector v of size n by n with all elements set to 0. This vector will store the generated matrix.
2)Initialize variables left, right, top, and bottom to keep track of the boundaries of the current spiral.
3)Initialize a variable val to keep track of the value to be filled in the matrix. It starts from 1 and
increments as we fill in the elements.
4)While the element at the center of the matrix is not filled (i.e., v[n/2][n/2] == 0), continue the spiral filling process.
5)Fill the top row of the current spiral from left to right with values from val and increment val.
6)Increment top to exclude the filled top row from future iterations.
7)Fill the right column of the current spiral from top to bottom with values from val and increment val.
8)Decrement right to exclude the filled right column from future iterations.
9)Fill the bottom row of the current spiral from right to left with values from val and increment val.
10)Decrement bottom to exclude the filled bottom row from future iterations.
11)Fill the left column of the current spiral from bottom to top with values from val and increment val.
12)Increment left to exclude the filled left column from future iterations.
13)Repeat steps 5 to 12 until the center element of the matrix is filled.
Finally, return the generated matrix v.

The code utilizes the four variables left, right, top, and bottom to keep track of the current boundaries of the spiral.
By incrementing or decrementing these boundaries, the code ensures that the next spiral is filled correctly.
The val variable is used to keep track of the value to be filled in the matrix. It starts from 1 and increments
after each element is filled.By following this spiral pattern and updating the boundaries accordingly,
the code generates the desired matrix.
*/

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int val = 1;
        while (v[n / 2][n / 2] == 0)
        {
            for (int i = left; i <= right; i++)
                v[top][i] = val++;
            top++;
            for (int i = top; i <= bottom; i++)
                v[i][right] = val++;
            right--;
            for (int i = right; i >= left; i--)
                v[bottom][i] = val++;
            bottom--;
            for (int i = bottom; i >= top; i--)
                v[i][left] = val++;
            left++;
        }
        return v;
    }
};

int main()
{
    return 0;
}