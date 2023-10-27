#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We implement Manacher's algorithm to find the longest palindromic substring in a given
string s. We transform the input string into a modified form, introducing special
characters to handle both even and odd-length palindromes. We then employ a dynamic
programming approach to efficiently compute the length of palindromes centered at each
position. We maintain a dynamic window (center and right boundary) and utilize symmetry
properties to avoid redundant computations. The final result is determined by finding
the longest palindrome and extracting the corresponding substring from the original input
string.
*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string str = "^#";
        for (char c : s)
        {
            str.push_back(c);
            str.push_back('#');
        }
        str.push_back('$');
        int size = str.length();
        vector<int> palindrome(size, 0);
        int mid = 0;
        int right = 0;
        for (int i = 1; i < size - 1; i++)
        {
            palindrome[i] = (right > i) ? min(right - i, palindrome[2 * mid - i]) : 0;
            while (str[i + 1 + palindrome[i]] == str[i - 1 - palindrome[i]])
            {
                palindrome[i]++;
            }
            if (i + palindrome[i] > right)
            {
                mid = i;
                right = i + palindrome[i];
            }
        }
        int maxLength = 0;
        int maxmid = 0;
        for (int i = 0; i < size; i++)
        {
            if (palindrome[i] > maxLength)
            {
                maxLength = palindrome[i];
                maxmid = i;
            }
        }
        int start = (maxmid - maxLength) / 2;
        int end = start + maxLength;
        return s.substr(start, end - start);
    }
};

int main()
{
    return 0;
}