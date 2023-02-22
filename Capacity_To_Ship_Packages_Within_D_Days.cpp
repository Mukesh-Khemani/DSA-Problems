#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        // left=Lower limit of binary search i.e. MAX element in the vector
        int left = *max_element(weights.begin(), weights.end());
        // right= Upper limit of binary search i.e. SUM of all the elements of the vector
        int right = accumulate(weights.begin(), weights.end(), 0);
        // BINARY SEARCH
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int curr = 0, requiredDays = 1;
            // counting the number of required days for 'mid' value
            for (int weight : weights)
            {
                if (curr + weight > mid)
                {
                    curr = 0;
                    requiredDays++;
                }
                curr += weight;
            }
            // if the required days for mid value are greator than given days then
            // we increase the 'mid' value
            if (requiredDays > days)
            {
                left = mid + 1;
            }
            // if the required days for mid value are less than or equal to
            // given days then we try to minimize the 'mid' value
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
int main()
{
    return 0;
}
