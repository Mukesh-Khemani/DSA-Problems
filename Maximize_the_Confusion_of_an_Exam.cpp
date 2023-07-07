#include <bits/stdc++.h>
using namespace std;
/*
INTUITION:
In this problem, we need to return the maximum number of consecutive 'T's or 'F's in the answer
key after performing the operation at most k times. This is a range finding question and we will
addressit with the usual, Sliding Window Algorithm. So we use a sliding window approach to maintain
a window of consecutive characters while keeping track of the count of flips within the window. We
maintain two separate windows, one for 'T' and one for 'F', to handle both cases. The variable "ans"
keeps track of the maximum length found so far.
*/
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int l = 0, r = 0, ans = 0, count = 0;
        while (r < answerKey.size())
        {
            if (answerKey[r] == 'T')
            {
                count++;
                while (count > k)
                {
                    if (answerKey[l] == 'T')
                    {
                        count--;
                    }
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        l = 0;
        r = 0;
        count = 0;
        while (r < answerKey.size())
        {
            if (answerKey[r] == 'F')
            {
                count++;
                while (count > k)
                {
                    if (answerKey[l] == 'F')
                    {
                        count--;
                    }
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}