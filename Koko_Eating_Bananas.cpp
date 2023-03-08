#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // INTUITION: As the answer is in the range of 1 to max(piles)
    // which refers to the maximum number of bananas among all the piles.
    // So as per the given constraints, the answer can be from 1 to 10^9.
    // But we have a huge search space and we are linearly iterating over
    // any possible answer. This would lead to a TLE.
    // So, in order to deal with this, we try to use binary search as at 
    // any instance in our search space, we can discard some part of the 
    // search space without any error.

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=0,high=INT_MAX;

        // BINARY SEARCH
        while(low+1<high){
            int mid=low+(high-low)/2;

            // 'x' s the total time taken by koko to eat bananas from all piles
            int x=0;
            for(int i=0;i<piles.size();i++){
                x+=(piles[i]/mid + (piles[i]%mid!=0));

                // To avoid redundant iterations due to overflow
                if(x>h) break;
            }
            if(x>h){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        return high;
    }
};

int main()
{
    return 0;
}