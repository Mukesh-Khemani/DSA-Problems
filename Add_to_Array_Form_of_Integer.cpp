#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0,x=0;
        for(int i=num.size()-1;i>=0;i--){
            x=k%10+num[i]+carry;
            if(x>=10){
                num[i]=x-10;
                carry=1;
            }
            else{
                num[i]=x;
                carry=0;
            }
            k/=10;
        }
        while(k){
            k+=carry;
            num.insert(num.begin(),k%10);
            k/=10;
            carry=0;
        }
        if(carry){
            num.insert(num.begin(),1);
        }
        return num;
    }
};
int main()
{
    return 0;
}