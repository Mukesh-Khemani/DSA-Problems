#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeviation(vector<int>& nums){
        // SET is the main data structure that was used in this problem
        set<int> s;
        // 'i' is a counter variable
        int i=0;
        /* First of all, insert the elements of the vector in the set in such a way 
        that if it is an even number, then we insert it as it is
        otherwise we multiply it by 2 and then insert it into the set. */
    while(i < nums.size()) {
        if (nums[i] % 2 == 0){
            s.insert(nums[i]);
        }
        else{
            s.insert(2 * nums[i]);
        }
        i++;
    }
    /* Now take the difference between the minimum and
     the maximum element of the set and store it in a variable called 'diff' */
    int diff = *s.rbegin() - *s.begin();
    /* This loop will run as long as
    1) The size of the set is greator than 0, and
    2) The last element i.e the rare end of the set is even */
    while (s.size() && *s.rbegin() % 2 == 0){
        // Store the max value of the set in max
        int max = *s.rbegin();
        // Remove the rare-end value from the set
        s.erase(max);
        // And insert the half of 'max' in the set
        s.insert(max / 2);
        /* After each iteration, keep on updating the value of 'diff'
        in such a way that it is the minimum of 'diff'(previous difference) and
        the current difference between the terminal value of the set.*/  
        diff = min(diff, *s.rbegin() - *s.begin());
    }
    // Return the value of 'diff'
    return diff;
    }
};
int main(){
    return 0;
}