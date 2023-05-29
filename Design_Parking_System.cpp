#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The addCar function is used to add a car to the parking system. It
takes a parameter carType that specifies the type of the car being added.
If there are available parking spots of the specified type, the function
decrements the count of available spots for that type and returns true to
indicate a successful addition. Otherwise, if no spots of the specified
type are available, it returns false.
*/

class ParkingSystem
{
public:
    int Vacant[3];
    ParkingSystem(int big, int medium, int small)
    {
        Vacant[0] = big;
        Vacant[1] = medium;
        Vacant[2] = small;
    }

    bool addCar(int carType)
    {
        if (Vacant[carType - 1])
        {
            Vacant[carType - 1]--;
            return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}