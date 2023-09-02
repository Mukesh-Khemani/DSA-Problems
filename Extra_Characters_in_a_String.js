
/*
INTUITION:
We start by iterating through s from right to left, considering 
substrings starting from each position. For each starting position, 
we calculate the minimum extra characters needed if no word from 
the dictionary is used. Then, we check all possible substrings from 
that position and update the minimum extra characters if a valid word 
is found in the dictionary. By considering all possible substrings and 
minimizing the extra characters at each step, we efficiently compute 
the minimum number of extra characters required to construct the entire 
string using words from the dictionary.
*/

var minExtraChar = function(s, dictionary)
{
    const n = s.length;
    const dictionarySet = new Set(dictionary);
    const dp = Array(n + 1).fill(0);
    for (let start = n - 1; start >= 0; start--)
    {
        dp[start] = dp[start + 1] + 1;
        for (let end = start; end < n; end++)
        {
            const curr = s.substring(start, end + 1);
            if (dictionarySet.has(curr))
                dp[start] = Math.min(dp[start], dp[end + 1]);
        }
    }
    return dp[0];
};
