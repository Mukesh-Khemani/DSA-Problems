#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The NestedIterator flattens a nested list by recursively processing each element,
storing the flattened integers in a separate vector. This separation simplifies
sequential iteration, providing efficient "next" and "hasNext" operations. The
flattening occurs during initialization, enabling quick access to the next element.
This design ensures clarity and conciseness, highlighting a clean separation between
the flattening process and iteration.
*/

class NestedIterator
{
    vector<NestedInteger> nestedList;
    vector<int> resultList;
    int currIndex = 0;
    void flatten(vector<NestedInteger> &currentList)
    {
        for (int i = 0; i < currentList.size(); i++)
        {
            if (currentList[i].isInteger())
                resultList.push_back(currentList[i].getInteger());
            else
                flatten(currentList[i].getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        this->nestedList = nestedList;
        flatten(nestedList);
    }

    int next()
    {
        int number = resultList[currIndex];
        currIndex++;
        return number;
    }

    bool hasNext()
    {
        return currIndex < resultList.size();
    }
};

int main()
{
    return 0;
}