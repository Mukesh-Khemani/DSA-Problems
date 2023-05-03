#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We need to find the unique elements in both the arrays. Also if there are duplicate
elements, we only need to store single entries.

APPROACH:
To avoid the problem of duplicacy, we can make use of set data structure.
-> First, we create two sets and push all the numbers of the arrays into each set
respectively.
-> Now, we have only unique numbers stored in the sets.
-> Then, we search for each number of a set in the other set.
-> If the number is not found in the other set, we append it into a new array.
-> We repeat the entire approach for both the arrays.
-> At the end, we append both the newly created arrays into a new array and return it.
*/

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> v1, v2;
        for (int i : s1)
        {
            if (s2.count(i) == 0)
                v1.push_back(i);
        }
        for (int i : s2)
        {
            if (s1.count(i) == 0)
                v2.push_back(i);
        }
        vector<vector<int>> v;
        v.push_back(v1);
        v.push_back(v2);
        return v;
    }
};

int main()
{
    return 0;
}