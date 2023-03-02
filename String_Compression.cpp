#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        // 'cur' -> current character
        // 'curCount' -> count of current character 
        char cur = chars[0];
        int n = chars.size(), curCount = 0, j = 0;
        // 'j' is a pointer to modify the input array

        for(int i = 0; i <= n; i++) {

            // if characters are same, increment count.
            if(i < n and cur == chars[i]) {
                curCount += 1;
            }

            // Add the character to the array
            // Add the character count to the array if count > 1
            // Update the current character and reset the count
            else {
                chars[j++] = cur;
                if(curCount > 1) {
                    string c = to_string(curCount);
                    for(auto k : c) {
                        chars[j++] = k;
                    }
                }
                if(i < n) cur = chars[i];
                curCount = 1;
            }
        }
        
        // The final value of the pointer will be the string length
        return j;
    }
};

int main()
{
    return 0;
}