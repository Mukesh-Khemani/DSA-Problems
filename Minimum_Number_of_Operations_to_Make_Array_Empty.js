/**
 * INTUITION:
 * The problem aims to calculate the minimum number of operations needed 
 * to make each element in the input array `nums` appear exactly three 
 * times. We use a Map (`count`) to store the frequency of each number in 
 * `nums`. We iterate through the counts and calculates the number of 
 * operations required to achieve the desired frequency of three for each 
 * unique element. If any element has a frequency other than one or a multiple 
 * of three, we return -1, indicating that it's not possible to achieve the 
 * desired distribution. Otherwise, we return the total number of operations 
 * needed to satisfy the condition for all elements in the array. The 
 * intuition behind this approach is to ensure that each distinct element 
 * appears exactly three times, and the minimum operations are calculated 
 * based on the current frequency of each element.
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    const count = new Map()
    for(const num of nums) count.set(num, (count.get(num) || 0) + 1)

    let ans = 0
    for(const c of count.values()){
        if(c===1) return -1
        ans += Math.ceil(c/3)
    }
    return ans
};