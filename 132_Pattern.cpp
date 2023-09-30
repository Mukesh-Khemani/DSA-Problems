#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is to identify the existence of a "132 pattern"
in a given array, where there exists an i-th index (i < j < k) such that
nums[i] < nums[k] < nums[j]. So we use a stack to keep track of potential candidates
for the third element of the pattern (`nums[k]`) as it iterates through the array
in reverse order. The variable `var` maintains the maximum value encountered so far
that could serve as the third element. We check if the current element (`nums[i]`)
is smaller than `var`; if true, it means a valid pattern has been found, and we
return true. The stack is used to find candidates for the third element, and as
elements are processed, is updated accordingly. If no pattern is found after the
entire array is processed, we return false.
*/

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> s;
        int third = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < third)
                return true;
            while (!s.empty() and s.top() < nums[i])
            {
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

int main()
{
    return 0;
}