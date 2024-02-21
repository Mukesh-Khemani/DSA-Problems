#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the bitwise AND of all numbers in the range
[left, right]. We achieve this by iteratively right shifting both left
and right until they become equal. In this way, we identify the common
prefix of the binary representations of left and right. The number of
times the binary digits are shifted determines the common prefix length,
which is stored in the variable count. Finally, the common prefix is
left shifted by count positions, effectively restoring the bitwise AND
of all numbers in the range [left, right].
*/

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int count = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            count++;
        }
        return (left << count);
    }
};

int main()
{
    return 0;
}