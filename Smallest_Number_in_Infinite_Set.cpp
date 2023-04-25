#include <bits/stdc++.h>
using namespace std;
/*
Solution:
We have to maintain a set of integers such that the smallest integers are always popped first,
and to ensure that the smallest integers not yet in the set are returned if the set is empty.
The count variable is used to keep track of the smallest integer not yet in the set. When
popSmallest() is called, it increments count to ensure that the next smallest integer is
returned next time. The addBack() function ensures that only integers smaller than the current
count are added to the set.
*/
class SmallestInfiniteSet
{
public:
    set<int> s;
    int count = 1;
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        int min1 = count;
        count++;
        if (s.empty())
            return min1;
        int min2 = *s.begin();
        if (min1 >= min2)
        {
            s.erase(s.begin());
            count--;
            return min2;
        }
        return min1;
    }

    void addBack(int num)
    {
        if (count <= num)
            return;
        s.insert(num);
    }
};

int main()
{
    return 0;
}