#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums.at(nums.size()-1)){
            return nums.size();
        }
        if(target<nums.at(0)){
            return 0;
        }
        int low=0,high=nums.size()-1, mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if(nums.at(mid)==target){
                return mid;
            }
            else if(nums.at(mid)>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    if(target<nums.at(low) && target>nums.at(low-1)){
        return low;
    }
    else{
        return low+1;
    }
}  
};
int main(){
    return 0;
}