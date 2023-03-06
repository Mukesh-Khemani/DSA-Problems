#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int a=0,i=0;
        while(k>0){
            a++;
            if(i<arr.size() && a==arr[i] ){ 
                i++;
            }
            else{
                k--;
            }
        }
        return a;
    }
};

int main()
{
    return 0;
}