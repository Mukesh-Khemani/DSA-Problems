#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given problem is based on the intuition that the letters vector is sorted in
ascending order and is circular. We have to find the smallest letter in the vector
that is greater than the target character.

APPROACH:
In summary, we use binary search to find the next greatest letter in the sorted and
circular letters vector. We specifically handle a special case where the target
is greater than or equal to the last element of the vector. The binary search loop
narrows down the search space by updating the low and high variables based on the
comparison with the target. The result is stored in the res variable and returned
at the end of the function.
*/

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int high = letters.size();
        if (target - letters[high - 1] >= 0)
            return letters[0];
        int low = 0;
        char res;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (letters[mid] > target)
            {
                high = mid - 1;
                res = letters[mid];
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}