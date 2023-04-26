#include <bits/stdc++.h>
using namespace std;

/*
INTUITION
Let us take num = 2147483647.
Iteration    Digits           Sum
    1)       2+1+4+7+4+       46
             8+3+6+4+7

    2)       4+6              10

    3)       1+0              1
In the above analysis, one can observe that 2147483647, 46, 10 and 1 all when
divided by 9 give the same remainder. Let us confirm our intuition with another
example : num = 92864759
Iteration    Digits          Sum
    1)       9+2+8+6+         50
             4+7+5+9

    2)       5+0              5

In this example also we can clearly observe that 92864759 and 50 have the same remainder
on dividion with 9. Hence, we can conclude that the sum of digits of the number will be
the number's remainder with 9 and if the number is divisible with 9, then the sum will
be 9. It could also be noticed that sum when num = 0 will be 0.

*/
class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        return num % 9 == 0 ? 9 : num % 9;
    }
};

/*
INTUITION:
We have to find the sum of digits of the number 'num' until we have a unit digit sum.
To do the same, we can keep on adding the digits of the number again and again until
we have a single digit sum. This is the naive approach.
SOLUTION:
In this approach, we keep on updating the number 'num' in each iteration.
After each iteration, if the value of 'num' is still greater than 9, we repeat the
entire process, until a single digit value is received.
Return the number in the end.
*/

class Solution
{
public:
    int addDigits(int num)
    {
        while (num > 9)
        {
            int x = 0;
            while (num)
            {
                x += num % 10;
                num /= 10;
            }
            num = x;
        }
        return num;
    }
};

int main()
{
    return 0;
}