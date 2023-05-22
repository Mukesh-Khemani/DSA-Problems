#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition is to find the k most frequent elements in a given vector.
This is achieved by counting the occurrences of each element using a frequency
map. By storing the frequencies in a priority queue, the elements with the highest
frequencies can be accessed easily.

APPROACH:
1) We start by creating a frequency map and populating it with the counts of each
element in the vector.
2) Then, we iterate over the frequency map and inserts pairs of frequency and element
values into the priority queue.
3) The priority queue automatically arranges the elements in descending order based on
their frequencies.
4) Next, we retrieve the top element from the priority queue (which has the highest
frequency) and adds it to the result vector.
5) This process is repeated k times to obtain the k most frequent elements.
*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto i : m)
        {
            pq.push(make_pair(i.second, i.first));
        }
        while (k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

int main()
{
    return 0;
}