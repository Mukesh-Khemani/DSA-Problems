/**
INTUITION: 
The problem aims to calculate the maximum score achievable by 
splitting a binary string s at any position and counting the 
number of '1's to the right of each split minus the number of 
'0's to the left. We initialize counters for '1's and '0's, as 
well as a variable to track the best score, starting from the 
leftmost side of the string. The function iterates through the 
string, updating the counters and the best score with each 
iteration. The final result is obtained by adding the count of 
'1's to the right of the last split position to the best score.
*/
/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function(s) {
    let ones=0
    let zeros=0
    let best=Number.MIN_SAFE_INTEGER
    for(let i=0;i<s.length-1;i++){
        if(s[i]=='1') ones++
        else zeros++
        best=Math.max(best,zeros-ones)
    }
    if(s[s.length-1]=='1') ones++
    return best+ones;

};