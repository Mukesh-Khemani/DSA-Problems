#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the maximum element after decrementing and rearranging
a given array. We use a counting approach to track the frequency of each element
in the array. We initialize a vector counts to store the counts of each element,
capped at the array size. We iterate through the input array, incrementing the
count of the minimum between the array element and its size in the counts vector.
Then, we iterate from 2 to the array size, updating the answer by taking the
minimum between the current answer plus the count of the current number and the
current number itself. Finally, we return the calculated maximum element.
*/

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> counts = vector(n + 1, 0);
        for (int i : arr)
            counts[min(i, n)]++;
        int ans = 1;
        for (int num = 2; num <= n; num++)
            ans = min(ans + counts[num], num);
        return ans;
    }
};

int main()
{
    return 0;
}