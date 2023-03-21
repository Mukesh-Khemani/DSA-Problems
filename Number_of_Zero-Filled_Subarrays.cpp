#include <bits/stdc++.h>
using namespace std;
/*
INTUITION:
We need to find a pattern for the number of sub-sets for any number of trailing zeroes.
For example: 
Consecutive Zeroes     Subsets
       1                 1
       2                 3
       3                 6
       4                 10
       5                 15....
To summarize, a general term in the number of sub-sets series is n*(n+1)/2, where
'n' is the number of consecutive zeroes.
*/
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,n=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                n++;
            }
            else{
                if(n!=0){
                    ans+=(n*(n+1)/2);
                    n=0;
                }
            }
        }

        // If the value of 'n' is not zero, this means that the last element in
        // the array is 0 and some sub-arrays are to be added to the result.
        ans+=(n*(n+1)/2);
        return ans;
    }
};

int main()
{
    return 0;
}