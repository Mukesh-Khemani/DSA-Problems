/**
 * INTUITION:
 * The problem aims to calculate the minimum number of operations required to 
 * make a binary string alternating. We iterate through the input string, checking 
 * if each character aligns with the expected pattern based on its index. For every 
 * mismatch, the counter `answer` is incremented. We then return the minimum of 
 * `answer` and the complement of `answer` with respect to the length of the string. 
 */
/**
 * @param {string} s
 * @return {number}
 */
var minOperations = function(s) {
    let answer=0
    for(let i=0;i<s.length;i++){
        if((i%2==0 && s[i]=='1') || (i%2 && s[i]=='0')) answer++
    }
    return Math.min(answer, s.length-answer)
};
