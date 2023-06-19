#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition is to iterate through the gain vector, continuously update the
current altitude by adding the gain value, and keep track of the maximum altitude
encountered. By comparing the current altitude with the maximum altitude and updating
it when necessary, we can find the highest altitude reached during the traversal.
*/

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxAltitude = 0, currentAltitude = 0;
        for (int i : gain)
        {
            currentAltitude += i;
            if (currentAltitude > maxAltitude)
                maxAltitude = currentAltitude;
        }
        return maxAltitude;
    }
};

int main()
{
    return 0;
}