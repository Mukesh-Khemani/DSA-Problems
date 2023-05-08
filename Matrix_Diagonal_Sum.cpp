#include <bits/stdc++.h>
using namespace std;
/*
INTUITION:
Given a square matrix 'mat', we have to return the sum of the matrix diagonals.
There are two types of diagonals of a matrix, namely Primary and Secondary.
The only difference in odd sized matrix and even sized matrix is that in even sized
square matrix, all the diagonal elements will be unique and in case of odd size,
the center element will be repeated twice.

For example:
1) n=3
        1 1 2
        1 4 1
        3 1 1
Here, the primary diagonal is {1,4,1} and secondary diagonal is {2,4,3}. So we can see
that the primary diagonal and the secondary diagonal have a number in common.

2) n=4
        1 2 3 2
        7 8 7 0
        9 6 4 9
        5 9 0 3
Here the primary diagonal is {1,8,4,3} and the secondary diagonal is {2,7,6,5}. So we
can see that none of the numbers are common between the primary and the secondary diagonal.

So, in case of odd size, we will have to subtract the overlapping element from the sum
as it is added twice.
*/

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int sum = 0, n = mat.size(), i = 0, j = n - 1;
        while (i < n and j >= 0)
        {
            sum += (mat[i][i] + mat[i][j]);
            i++;
            j--;
        }
        return (n % 2) ? sum - mat[n / 2][n / 2] : sum;
    }
};

int main()
{
    return 0;
}