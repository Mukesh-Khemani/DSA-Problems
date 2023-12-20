/*
INTUITION:
The problem aims to determine the amount of money remaining after purchasing two 
chocolate bars with the given prices. We initialize variables `smallest` and 
`secondSmallest` to store the two smallest prices encountered during iteration 
through the `prices` array. We update these variables while traversing the array, 
ensuring that `smallest` always holds the smallest price and `secondSmallest` 
holds the second smallest. Finally, we return the difference between the total cost 
of the two chocolates and the initial amount of money, or the original amount of 
money if it's insufficient to purchase both chocolates.
*/

/**
 * @param {number[]} prices
 * @param {number} money
 * @return {number}
 */
var buyChoco = function(prices, money) {
    let smallest=Math.min(prices[0],prices[1])
    let secondSmallest=Math.max(prices[0],prices[1])
    for(let i=2;i<prices.length;i++){
        if(prices[i]<secondSmallest){
            if(prices[i]<smallest){
                secondSmallest=smallest
                smallest=prices[i]
            }
            else secondSmallest=prices[i]
        }
    }
    return smallest+secondSmallest<=money ? money-(smallest+secondSmallest):money
};