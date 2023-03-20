#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In order to place a tree at the start or the end, we need two consecutive empty places
and in any other case, we need three consecutive empty places so as to meet the 
no-adjacent-flowers rule i.e.  flowers cannot be planted in adjacent plots.
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size() and n;i++){
            if(flowerbed[i]==0 and (i==0 or flowerbed[i-1]==0) and 
            (i==flowerbed.size()-1 or flowerbed[i+1]==0)){
                flowerbed[i]=1;
                n--;
            }
        }
        return n==0;
    }
};

int main()
{
    return 0;
}