#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We only need to return the first or the last element during 'back' and 'forward' function.
For this reason, we use array as the time complexity to access the elements of a 
particular index is O(1). Also, the manipulation of an array is easier as compared to other data structures.
Algorithm:
-> BrowserHistory: Initializes the object with the homepage of the browser.
Functions:
- visit:- Visits url from the current page. It clears up all the forward history (for this, we use resize function).
- back:-Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
- forward:- Move steps forward in history. If the forward number of steps exceeds the length of the array, UPDATE 'curr' to the last element of the array. If not, move forward 'steps' steps and UPDATE the 'curr' to that position. Return the current url. 
*/

class BrowserHistory {
public:
    vector<string> s;
    int curr=-1;
    BrowserHistory(string homepage) {
        s.push_back(homepage);
        curr++;
    }
    void visit(string url) {
        s.resize(curr+1);
        s.push_back(url);
        curr++;
    }
    string back(int steps) {
        if(curr-steps>0) {
            curr-=steps;
        } else  {
            curr=0;
        }
        return s[curr];
    }
    string forward(int steps) {
        if(curr+steps<s.size()) {
            curr+=steps;
        } else  {
            curr=s.size()-1;
        }
        return s[curr];
    }
};

int main()
{
    return 0;
}