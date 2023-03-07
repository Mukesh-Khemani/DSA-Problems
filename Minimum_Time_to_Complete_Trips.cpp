#include <bits/stdc++.h>
using namespace std;

/*INTUITION: 
As per the constraints of the problem, brute force would give TLE. So rather than 
brute force, we can take use binary search to cut the search space by half each time 
to locate the minimum valid time. Start with initializing the left (lower boundary) 
as left = 1 since it is the minimum possible valid time and the right (upper boundary) as 
right = 10^14(maximum time as per constraints) where maximum_time equals the maximum time 
taken by one trip, so right is guaranteed to be long enough. Therefore, the minimum time 
is included in this search space.

Then we keep checking if  mid which is the average of left and right is long enough.

If not, it means mid is too short and we shall cut the half containing smaller values i.e 
increase left = mid+1, otherwise, we shall cut the half containing higher values i.e decrease 
right = mid . Then we move on to the remaining half and repeat the process until there is 
only one time left, which is the minimum valid time.
*/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {

        
        long long left=1, right=1e14;
        while(left<right){

            // BINARY SEARCH 
            long long mid=left+(right-left)/2;
            long Time=0;
            for(int i=0;i<time.size();i++){
                Time+=mid/time[i];
            }
            if(Time<totalTrips){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return left;
    }
};

int main()
{
    return 0;
}