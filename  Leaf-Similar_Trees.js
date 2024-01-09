/**
 * INTUITION:
 * The provided JavaScript code defines a function `leafSimilar` that determines if the leaf 
 * sequences of two given binary trees, `root1` and `root2`, are similar. It uses a depth-first 
 * search (DFS) approach to traverse each tree, collecting the values of leaf nodes in separate 
 * arrays (`leaves1` and `leaves2`). The function then checks if the lengths of the two leaf 
 * arrays are equal and if every corresponding element in the arrays matches. If both conditions 
 * are met, the function returns true, indicating that the leaf sequences of the two trees are 
 * similar; otherwise, it returns false. This algorithm leverages DFS to efficiently compare the 
 * leaf values of the given binary trees and is particularly useful when checking for structural 
 * and sequential similarity in leaf nodes.
 */

var leafSimilar = function(root1, root2) {
    dfs = function(node, leaves){
        if(node != null){
            if(node.left == null && node.right == null) leaves.push(node.val)
            dfs(node.left, leaves)
            dfs(node.right, leaves)
        }
    }
    let leaves1 = []    
    let leaves2 = []
    dfs(root1, leaves1)    
    dfs(root2, leaves2)
    return leaves1.length == leaves2.length && leaves1.every((v, i) => v === leaves2[i])   
};