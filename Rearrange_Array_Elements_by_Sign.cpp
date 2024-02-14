#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to rearrange an array by separating positive and negative
integers into alternate positions, starting with positive integers at even
indices and negative integers at odd indices. We initialize two pointers,
positive and negative, to keep track of the positions where positive and
negative integers should be placed, respectively. We iterate through the
input array, assigning positive integers to positions determined by the
positive pointer and negative integers to positions determined by the
negative pointer. The final rearranged array is then returned.
*/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n, 0);
        int positive = 0, negative = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                answer[positive] = nums[i];
                positive += 2;
            }
            else
            {
                answer[negative] = nums[i];
                negative += 2;
            }
        }
        return answer;
    }
};

int main()
{
    return 0;
}