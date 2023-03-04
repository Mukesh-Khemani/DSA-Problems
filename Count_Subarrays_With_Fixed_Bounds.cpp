#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long ans = 0;
    int j = -1, minIndex = -1, maxIndex = -1;

    for (int i = 0; i < nums.size(); ++i) {

        // Update 'j' if the number at ith index is 
        // < minK or > maxK
        if(nums[i] < minK or nums[i] > maxK){
            j = i;
        }

        // Update 'minIndex' to the index at which 'minK' is found
        if(nums[i] == minK){
            minIndex = i;
        }

        // Update 'maxIndex' to the index at which 'maxK' is found
        if(nums[i] == maxK){
            maxIndex = i;
        }

        // 'ans' is only incremented if both 'minIndex' and 'maxIndex'
        // are found and the subset contains no values greater than
        // 'maxK' and less than 'minK'
        ans += max(0, min(minIndex, maxIndex) - j);
    }
    
    return ans;
  }
};



int main()
{
    return 0;
}