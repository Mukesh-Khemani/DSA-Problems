/* 
INTUITION:
The problem aims to calculate the maximum difference of the product of two distinct 
elements in an array of numbers. By maintaining four variables (`largest`, `secondLargest`, 
`smallest`, and `secondSmallest`), we iterate through the array, updating these variables 
to keep track of the two largest and two smallest elements. This approach eliminates the 
need for sorting the array and enhances computational efficiency. The final result is 
computed by finding the product of the two largest elements and subtracting the product 
of the two smallest elements. 
*/
var maxProductDifference = function(nums) {
    let largest = 0, secondLargest = 0;
    let smallest = Number.MAX_SAFE_INTEGER, secondSmallest = Number.MAX_SAFE_INTEGER;

    for (const n of nums) {
        if (n < smallest) {
            secondSmallest = smallest;
            smallest = n;
        } else if (n < secondSmallest) secondSmallest = n;

        if (n > largest) {
            secondLargest = largest;
            largest = n;
        } else if (n > secondLargest) secondLargest = n;   
    }

    return (largest * secondLargest) - (smallest * secondSmallest);
};