#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the given approach, we use binary search to efficiently determine if a target
integer exists in a sorted 2D matrix. We check each element in the matrix and
update the search range based on the comparison with the target.
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int x = matrix[mid / m][mid % m];
            if (x > target)
                right = mid - 1;
            else if (x < target)
                left = mid + 1;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}