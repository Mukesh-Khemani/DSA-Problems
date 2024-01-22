#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find and return a pair of integers, where one is a repeated
number and the other is a missing number in a given vector `nums`. We use an
unordered map `freq` to keep track of the frequency of each element in the vector.
We iterate through the vector, updating the frequency map and identifying the
repeated number when the frequency becomes 2. Additionally, we identify the missing
number by iterating from 1 to the size of the vector and finding the first element
with a frequency of 0.
*/

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int repeated_number = 0, missing_number = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            if (freq[nums[i]] == 2)
            {
                repeated_number = nums[i];
            }
        }
        for (int i = 1; i < nums.size() + 1; i++)
        {
            if (freq[i] == 0)
            {
                missing_number = i;
                break;
            }
        }
        return {repeated_number, missing_number};
    }
};

int main()
{
    return 0;
}