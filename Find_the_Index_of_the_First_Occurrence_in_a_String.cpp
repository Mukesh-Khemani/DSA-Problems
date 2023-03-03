#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int strStr(string haystack, string needle){

        // The string 'needle' cannot occur if its size is greater
        // than the size of the string 'haystack'
        if(haystack.length()<needle.length()) return -1;

        // Now, check all substrings of the string 'haystack' one 
        // by one. If the substring 'needle' is found 
        // return its index.
        int i=0;
        while(i<haystack.length()-needle.length()+1){
            if(haystack.at(i)==needle.at(0)){
                int j=0;
                int k=i;
                while(haystack.at(k)==needle.at(j)){
                    if(j==needle.length()-1){
                        return i;
                    }
                    j++;
                    k++;
                }
            }
            i++;
        }
        return -1;
    }
};

int main()
{
    return 0;
}