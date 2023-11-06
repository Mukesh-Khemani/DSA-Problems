#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The aim of this problem is to manage seat reservations in a venue.
The class uses an integer variable `curr` to keep track of the next
available seat number and a set `seats` to store reserved seat
numbers. The constructor initializes `curr` to 1. The reserve()
function checks if there are any reserved seats in the `seats` set,
and if so, we return the smallest reserved seat number and remove it
from the set. Otherwise, we return the current seat number and increments
`curr`. The unreserve() function adds a seat number to the `seats` set,
making it available for future reservations.
*/

class SeatManager
{
    int curr;
    set<int> seats;

public:
    SeatManager(int n)
    {
        curr = 1;
    }

    int reserve()
    {
        if (!seats.empty())
        {
            int seatNumber = *seats.begin();
            seats.erase(seats.begin());
            return seatNumber;
        }
        int seatNumber = curr;
        curr++;
        return seatNumber;
    }

    void unreserve(int seatNumber)
    {
        seats.insert(seatNumber);
    }
};

int main()
{
    return 0;
}