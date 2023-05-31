#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this question, we have to calculate the average time a train takes to travel from one station to another.
And to implement this, we use two hashmaps:
1) map1: This map stores the check-in information for each passenger. The key is the passenger's ID, and the value
is a pair consisting of the station name and the check-in time.
2) map2: This map stores the aggregated travel information for each pair of stations. The key is a concatenation of
the start and end station names, separated by a "-". The value is a pair consisting of the total travel
time and the number of trips made between those stations.
*/

class UndergroundSystem
{
public:
    unordered_map<int, pair<string, int>> map1;
    unordered_map<string, pair<int, int>> map2;
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t)
    {
        map1[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t)
    {
        auto checkInInfo = map1[id];
        map1.erase(id);
        string travel = checkInInfo.first + "-" + stationName;
        int travelTime = t - checkInInfo.second;
        if (map2.find(travel) != map2.end())
        {
            map2[travel].first += travelTime;
            map2[travel].second++;
        }
        else
        {
            map2[travel] = make_pair(travelTime, 1);
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        startStation += ("-" + endStation);
        return (double)map2[startStation].first / map2[startStation].second;
    }
};

int main()
{
    return 0;
}