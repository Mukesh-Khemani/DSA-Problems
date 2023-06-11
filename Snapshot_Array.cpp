#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We have to create a class that maintains a history of element values for each snapshot using
a vector of maps. Each time a snapshot is taken, the current values of the elements are stored
in their respective maps with the current snapshot ID.

If we store the entire array at the time of the snapshot, the space required for such and operation
will exceed the memory limit. So we need to look for an optimised approach. This pushes our thought
process towards map data structure as we need to store the values at a given index and update them
with the set function. So we create a map for each element of the array and modify them accordingly.

When retrieving a value for a specific snapshot ID, the class performs a binary search in the map
for the given index to find the closest previous snapshot ID and returns the corresponding value.
*/

class SnapshotArray
{
    vector<map<int, int>> vector;
    int snap_id;

public:
    SnapshotArray(int length)
    {
        vector.resize(length);
        for (auto &it : vector)
        {
            it[0] = 0;
        }
        snap_id = 0;
    }

    void set(int index, int val)
    {
        vector[index][snap_id] = val;
    }

    int snap()
    {
        return snap_id++;
    }

    int get(int index, int snap_id)
    {
        map<int, int> &m = vector[index];
        auto i = m.upper_bound(snap_id);
        return (--i)->second;
    }
};

int main()
{
    return 0;
}