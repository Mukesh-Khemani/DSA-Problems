/**
 * INTUITION:
 * The intuition lies in recursively traversing a binary tree while maintaining the minimum and maximum 
 * values encountered along the path from the root to each node. During traversal, we calculate the absolute 
 * differences between the node values and the current minimum and maximum. The maximum difference is updated 
 * accordingly, ensuring that the final result captures the maximum difference between any ancestor-descendant 
 * pair in the tree.
 */

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxAncestorDiff = function(root) {
    if(!root) return 0
    let difference=0
    helper(root, root.val, root.val)
    return difference

    function helper(root, minVal, maxVal){
        if(!root) return
        difference = Math.max(difference, Math.max(Math.abs(minVal - root.val), Math.abs(maxVal - root.val)))
        minVal = Math.min(minVal, root.val)
        maxVal = Math.max(maxVal, root.val)
        helper(root.left, minVal, maxVal)
        helper(root.right, minVal, maxVal)
    }
};