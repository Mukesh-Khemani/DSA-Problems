#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to systematically generating all possible sequential
digits within the given range [low, high]. Starting with single-digit
numbers from 1 to 9, we iterate through each digit, appending subsequent
digits until the generated number exceeds the upper limit high or the
next digit exceeds 9. At each iteration, we check if the generated number
falls within the range [low, high]. If so, we add the number to the
result vector. Finally, the result vector is sorted to ensure the
sequential digits are in ascending order before returning the final output.
*/

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> result;
        for (int i = 1; i <= 9; i++)
        {
            int num = i;
            int next = i + 1;
            while (num <= high and next <= 9)
            {
                num = num * 10 + next;
                if (low <= num and num <= high)
                    result.push_back(num);
                next++;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    return 0;
}