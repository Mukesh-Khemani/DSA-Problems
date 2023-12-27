/**
 * INTUITION:
 * The problem aims to calculate the minimum cost required to paint a sequence 
 * of colors based on the given input arrays `colors` and `neededTime`. We 
 * iterate through the colors and their corresponding needed times, identifying 
 * contiguous segments of the same color. Within each segment, we compute the 
 * total time required to paint that color and subtracts the maximum needed time, 
 * representing the cost-saving strategy. We then accumulate the total time for 
 * all segments, providing the minimum cost to achieve the desired color sequence.
 */


/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function(colors, neededTime) {
    let totalTime=0
    let i=0,j=0
    while(i<neededTime.length && j<neededTime.length){
        let currTotal=0
        let currMax=0
        while(j<neededTime.length && colors[i]===colors[j]){
            currTotal+=neededTime[j]
            currMax=Math.max(currMax,neededTime[j])
            j++
        }
        totalTime+=currTotal-currMax
        i=j
    }
    return totalTime
};