#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //Here, take a vector of vector which matches the capital from capital vector
        //to its corresponding profit in profits vector
        vector<vector<int>> v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        // now we need to sort this vector of vectors(v)
        sort(v.begin(),v.end());
        //This is the main DATA STRUCTURE i.e. Priority Queue
        priority_queue<int> pq;
        int i=0;
        while(k){
            // if the value of the capital of the ith index is less than or
            // equal to the weight and the counter 'i' is less than the size 
            // of the vector capital, we push it to the priority queue and 
            //increment the value of 'i'
            if(i<capital.size() && w>=v[i][0]){
                pq.push(v[i][1]);
                i++;
            }
            // else if the priority queue is not empty, we add the top 
            //of the queue to weight and pop the top of the priority queue 
            // and simultaneously decrease k by 1; 
            else if(!pq.empty()){
                w+=pq.top();
                pq.pop();
                k--;
            }
            else{
                break;
            }
        }
        // we return the value of weight
        return w;
    }
};
int main(){
    return 0;
}