#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We need to calculate the count of "nice pairs" in the given vector.
A nice pair is defined as a pair of indices (i, j) where i is not
equal to j, and nums[i] - rev(nums[i]) is equal to nums[j] - rev(nums[j]).
We create a new vector arr, where each element is the difference between
an element in nums and its reverse obtained by the rev function. We then
use an unordered_map to keep track of the count of each unique element in
arr and calculate the final count of nice pairs.
*/

int MOD = 1e9 + 7;
class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back(nums[i] - rev(nums[i]));
        }
        unordered_map<int, int> map;
        int ans = 0;
        for (int num : arr)
        {
            ans = (ans + map[num]) % MOD;
            map[num]++;
        }
        return ans;
    }

    int rev(int num)
    {
        int result = 0;
        while (num > 0)
        {
            result = result * 10 + num % 10;
            num /= 10;
        }
        return result;
    }
};

int main()
{
    return 0;
}