#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition lies in utilizing the array itself to mark the presence of elements.
Since the array elements are in the range [1, n], we can exploit this fact to mark
visited elements. For each element `nums[i]`, we access the index `abs(nums[i]) - 1`
and negate the value at that index to indicate that we have encountered the
corresponding number. If we encounter a negative value at that index during
subsequent iterations, it implies that the number has already been visited,
indicating a duplicate. We then add the index plus one (to convert it back to the
original number) to the result vector.
*/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                result.push_back(index + 1);
            else
                nums[index] = -nums[index];
        }
        return result;
    }
};

int main()
{
    return 0;
}