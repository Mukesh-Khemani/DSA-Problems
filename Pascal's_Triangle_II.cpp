#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We first initialize a vector `v` with `row+1` elements, all set to 1.
We then iteratively update the elements of `v` by calculating binomial
coefficients using a formula that involves a temporary variable `temp`.
The loop runs from 1 to `row`, and in each iteration, `temp` is updated
by multiplying it with `row-i+1` and dividing it by `i`, and the result
is assigned to the corresponding element in `v`.
*/

class Solution
{
public:
    vector<int> getRow(int row)
    {
        vector<int> v(row + 1, 1);
        long int temp = 1;
        for (int i = 1; i <= row; i++)
        {
            temp = temp * (row - i + 1) / i;
            v[i] = temp;
        }
        return v;
    }
};

int main()
{
    return 0;
}