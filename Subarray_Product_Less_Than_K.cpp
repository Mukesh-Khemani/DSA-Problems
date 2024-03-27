#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition lies in counting the number of subarrays whose product is less
than a given value 'k'. To achieve this, we use a sliding window approach,
where a window is expanded from the right end while ensuring that the product
of elements within the window remains less than 'k'. Whenever the product
exceeds 'k', the window contracts from the left end until the product falls
below 'k' again. By counting the number of valid subarrays for each window
configuration, we compute the total count of subarrays with a product less
than 'k'.
*/

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int count = 0;
        int product = 1;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            product *= nums[right];
            while (product >= k)
                product /= nums[left++];
            count += right - left + 1;
        }
        return count;
    }
};

int main()
{
    return 0;
}