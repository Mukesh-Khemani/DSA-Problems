#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to determine if the occurrences of unique elements in the input
vector `arr` are also unique. The approach involves first sorting the vector for
consecutive occurrences to be adjacent. We use two sets, `number` to keep track of
unique elements and `numberCount` to store the count of occurrences for each unique
element. By iterating through the sorted vector, we count consecutive occurrences
of the same element and inserts the count into `numberCount` when a different element
is encountered. Finally, we compare the sizes of the sets `number` and `numberCount`
to ascertain whether the occurrences of unique elements are indeed unique.
*/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        set<int> number;
        set<int> numberCount;
        for (int i = 0; i < arr.size(); i++)
            number.insert(arr[i]);
        int count = 1;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i + 1])
                count++;
            if (arr[i] != arr[i + 1])
            {
                numberCount.insert(count);
                count = 1;
            }
        }
        numberCount.insert(count);
        return number.size() == numberCount.size();
    }
};

int main()
{
    return 0;
}