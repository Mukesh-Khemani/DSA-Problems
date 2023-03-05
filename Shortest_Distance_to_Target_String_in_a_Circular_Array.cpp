#include <bits/stdc++.h>
using namespace std;

 

class Solution {
public:

    // INTUITION : First we have to find the target. Then find 
    // the shortest distance between the target and the 'startIndex'.
    // The minimum distance could either be from the left or from the right.
    // If on moving towards left the 0th index is achieved, continue from 
    // the end. Similarly, if we reach the end of the array while moving 
    // towards right, continue from the beginning.

    int closetTarget(vector<string>& words, string target, int startIndex){
        int n=words.size(),Min=INT_MAX,ans=Min;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                Min=min(abs(i-startIndex),n-abs(i-startIndex));
                ans=min(Min,ans);
            }
        }
        if(Min!=INT_MAX) return ans;
        return -1;
    }
};

int main()
{
    return 0;
}