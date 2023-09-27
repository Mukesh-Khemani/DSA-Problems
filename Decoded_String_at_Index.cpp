#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is to decode a given encoded string,
starting from the end and working backward. The goal is to find the k-th
character in the decoded string. To achieve this, we calculate the total
size of the decoded string by iteratively processing the encoded string.
We consider the digit characters as multipliers for the size and increments
the size for alphabetic characters. Then, we use a backward traversal to
update `k` by taking the modulo of `k` with the current size, ensuring that
`k` is within the bounds of the remaining decoded string. If `k` becomes zero
and the current character is alphabetic, we return that character. If `k` is
not found after processing the entire string, an empty string is returned.
*/

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long size = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
                size *= s[i] - '0';
            else
                size++;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            k %= size;
            if (k == 0 and isalpha(s[i]))
                return string(1, s[i]);
            if (isdigit(s[i]))
                size /= s[i] - '0';
            else
                size--;
        }
        return "";
    }
};

int main()
{
    return 0;
}