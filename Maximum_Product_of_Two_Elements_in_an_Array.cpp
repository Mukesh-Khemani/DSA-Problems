#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the maximum product of two distinct elements
in the given vector `nums`. We iterate through the array, updating the
two largest elements encountered so far, `largest` and `secondLargest`.
By comparing each element with the current largest element, we ensure
the correct assignment of values to find the top two elements. Finally,
we return the product of these two largest elements minus one, as we seek
the maximum product of two distinct elements.
*/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int largest = 0;
        int secondLargest = 0;
        for (int num : nums)
        {
            if (num > largest)
            {
                secondLargest = largest;
                largest = num;
            }
            else
                secondLargest = max(num, secondLargest);
        }
        return (largest - 1) * (secondLargest - 1);
    }
};

int main()
{
    return 0;
}