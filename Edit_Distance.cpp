#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Memoization(int i, int j, string &s1, string &s2,
     vector<vector<int>> &dp){
        // Base Case: If one string is exhausted, 
        // then number of operations is remaining charaters 
        // of the other string(current index of the other string +1)
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        // If operations for indices 'i' and 'j' are already calculated, 
        // return the Memoized value
        if(dp[i][j] != -1) return dp[i][j];

        // If the characters are same, then no need to perform any operation
        // Hence, move ahead in both strings
        if(s1[i] == s2[j]) return dp[i][j] = Memoization(i-1, j-1, s1, s2, dp);
        
        // Recursively compute minimum cost for all 
        // three operations and take minimum of the three values
        // Insert: Recur for i and j-1
        // Remove: Recur for i-1 and j
        // Replace: Recur for i-1 and j-1
        return dp[i][j] = 1 + min(Memoization(i-1, j, s1, s2, dp ),
        min(Memoization(i, j-1, s1, s2, dp ),
        Memoization(i-1, j-1, s1, s2, dp )));
    }

    int minDistance(string s1, string s2) {
        // Initializing 2-D array
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));

        return Memoization(s1.length()-1,s2.length()-1,s1,s2,dp);
    }
};
int main(){
    return 0;
}
