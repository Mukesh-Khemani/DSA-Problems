/**
 * INTUITION:
 * The function aims to calculate the sum of node values within the specified 
 * range [low, high] in a binary search tree (BST). We follow a recursive approach 
 * to traverse the tree nodes. For each node, we check if its value falls within 
 * the given range. If so, the node's value is added to the current sum (currVal).
 * We then recursively call itself for the left and right subtrees to accumulate the 
 * sum of values within the range. The final result is the sum of values satisfying 
 * the condition in the entire BST.
 */
/**
 * @param {TreeNode} root
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var rangeSumBST = function(root, low, high) {
    if(!root) return 0
    const currVal = (root.val >= low && root.val<=high) ? root.val : 0

    const leftSum = rangeSumBST(root.left, low, high)
    const rightSum = rangeSumBST(root.right, low, high)

    return currVal + leftSum + rightSum
};