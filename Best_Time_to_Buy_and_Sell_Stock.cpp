#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices){
        // 'maxProfit' is a variable which stores the value of the maximum profit 
        // (i.e. Highest stock price - Lowest stock price)
        int maxProfit=0;
        // 'Minimum' stores the value of the minimum value of stock price 
        int Minimum=prices[0];
        // This is a loop which starts from i=0 and 
        // iterates until i=sizeof(prices)-1
        for(int i=0;i<prices.size();i++){
            // Keep on updating the value of Minimum to the minimum
            // of (Minimum,prices[i])
            Minimum=min(Minimum,prices[i]);
            // Declare a variable 'Profit' which is equal to the difference of 
            // prices[i] and Minimum
            int Profit=prices[i]-Minimum;
            // At the end of each iteration, update maxProfit to the 
            //maximum value of Profit and maxProfit
            maxProfit=max(Profit,maxProfit);
        }
        // Return the last updated value of maxProfit as RESULT.
        return maxProfit;
    }
};

int main(){
    return 0;
}