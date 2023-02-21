#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        while(low<high){
            mid=(low+high)/2;
            if(((mid%2)==0 && nums[mid]==nums[mid+1]) || ((mid%2)==1 && 
            nums[mid]==nums[mid-1])){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return nums[low];
    }
};
int main(){
    return 0;
}