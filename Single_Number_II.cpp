#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we need to find the single element. We must implement a solution
with a linear runtime complexity and use only constant extra space. So we use XOR
operation. The intuition behind the XOR-based approach is that XOR operation has
the property of being both commutative and associative. This property allows us to
effectively cancel out pairs of numbers that appear twice, leaving only the number
that appears once.
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0, twos = 0;
        for (int num : nums)
        {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

int main()
{
    return 0;
}