#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
Let us take n=10 and try to observe the pattern carefully:
Bulb No./    1st      2nd     3rd     4th     5th     6th     7th     8th     9th     10th
Round
   1)        ON       ON      ON      ON      ON      ON      ON      ON      ON      ON
   2)        ON       OFF     ON      OFF     ON      OFF     ON      OFF     ON      OFF
   3)        ON       OFF     OFF     OFF     ON      ON      ON      OFF     OFF     OFF
   4)        ON       OFF     OFF     ON      ON      ON      ON      ON      OFF     OFF
   5)        ON       OFF     OFF     ON      OFF     ON      ON      ON      OFF     ON
   6)        ON       OFF     OFF     ON      OFF     ON      ON      ON      OFF     ON
   7)        ON       OFF     OFF     ON      OFF     OFF     OFF     ON      OFF     ON
   8)        ON       OFF     OFF     ON      OFF     OFF     OFF     OFF     OFF     ON
   9)        ON       OFF     OFF     ON      OFF     OFF     OFF     OFF     ON      ON
   10)       ON       OFF     OFF     ON      OFF     OFF     OFF     OFF     ON      OFF
From the above table, we can also get the number of switched on bulbs less than or equal to 10
just by observing ith row of the i*i matrix (where i<=10).
1) num=1 bulbsOn=1
2) num=2 bulbsOn=1
3) num=3 bulbsOn=1
4) num=4 bulbsOn=2
5) num=5 bulbsOn=2
6) num=6 bulbsOn=2
7) num=7 bulbsOn=2
8) num=8 bulbsOn=2
9) num=9 bulbsOn=3
10) num=10 bulbsOn=3
So from the above examples, we can conclude that the number of 'on' bulbs after nth round
will be sqrt(n).

*/

class Solution
{
public:
    int bulbSwitch(int n)
    {
        return sqrt(n);
    }
};

int main()
{
    return 0;
}