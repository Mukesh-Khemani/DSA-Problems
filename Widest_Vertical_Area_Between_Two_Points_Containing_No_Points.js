/*
INTUITION:
The problem aims to calculate the maximum width of a vertical area 
formed by a set of points in a 2D plane. We begin by sorting the 
given array of points based on their x-coordinates using the `sort` 
method. We then iterate through the sorted array, calculating the 
horizontal distance between adjacent points and updating the maximum 
width (`ans`). The final result represents the maximum separation 
between two x-coordinates in the sorted array, indicating the widest 
possible vertical area. 
*/

/**
 * @param {number[][]} points
 * @return {number}
 */
var maxWidthOfVerticalArea = function(points) {
    points.sort((a, b) => a[0] - b[0]);        
    let ans = 0;
    for (let i = 1; i < points.length; i++) {
        ans = Math.max(ans, points[i][0] - points[i - 1][0]);
    }        
    return ans;
};