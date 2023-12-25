/**
 * INTUITION:
 * We use a recursive approach with memoization to calculate the number of ways to 
 * decode a given string `s`. The base case checks if the current index has reached 
 * the length of the string, returning 1 if true. If the current character is '0', 
 * it indicates an invalid decoding, so '0' is returned. The memoization array 
 * (`memo`) is consulted to check if the result for the current index has already 
 * been computed, avoiding redundant calculations. We calculate the total ways by 
 * recursively calling itself for the next index and, if a valid two-digit number 
 * exists, for the index after skipping one more character. 
 */
var numDecodings = function(s) {
    const memo = new Array(s.length).fill(-1)

    const helper = (index) => {
        if(index === s.length) return 1

        if(s[index] === '0') return 0

        if(memo[index] !== -1) return memo[index] 

        let ways = helper(index + 1)

        if(index < s.length - 1 && parseInt(s.substring(index, index+2)) <= 26){
            ways += helper(index+2)
        }
        memo[index] = ways
        return ways
    };
    return helper(0)
};