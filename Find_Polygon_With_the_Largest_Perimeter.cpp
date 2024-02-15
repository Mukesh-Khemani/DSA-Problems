#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the largest perimeter among all possible triangles
that can be formed using elements from the given vector `nums`. We begin by
sorting the elements in ascending order, which facilitates identifying the
longest side of a potential triangle. Then, we iterate through the sorted
array, maintaining a cumulative sum `currentSum` as it examines each element.
If a current element is less than the cumulative sum (indicating that it could
be part of a valid triangle), we update the `result` variable with the sum of
the current element and the cumulative sum. Finally, we return the largest
value encountered, representing the largest perimeter among the potential
triangles formed.
*/

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        long long currentSum = 0, result = -1;
        for (int num : nums)
        {
            if (num < currentSum)
                result = num + currentSum;
            currentSum += num;
        }
        return result;
    }
};

int main()
{
    return 0;
}