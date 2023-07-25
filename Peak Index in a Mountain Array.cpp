#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
1) If the middle element (mid) is greater than both its neighboring elements, it means we have
found a peak, and we return its index mid.
2) If the element at mid is not a peak, it must either be part of an increasing segment or a
decreasing segment of the mountain array.
- If the element to the left of mid is greater than the element at mid, it means the peak must
be on the left side of mid, so we perform the binary search on the left half of the array.
- Otherwise, the peak must be on the right side of mid, so we perform the binary search on
the right half of the array.
*/

class Solution
{
    int helper(vector<int> &arr, int low, int high, int n)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) and (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return mid;
        else if (mid > 0 and arr[mid - 1] > arr[mid])
            return helper(arr, low, mid - 1, n);
        return helper(arr, mid + 1, high, n);
    }

public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        return helper(arr, 0, n - 1, n);
    }
};

int main()
{
    return 0;
}