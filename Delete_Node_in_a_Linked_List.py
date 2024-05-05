# INTUITION:
# The intuition is to remove the given node by replacing its value with the value of 
# its next node, effectively skipping the current node. By doing so, the current node 
# effectively gets removed from the linked list. Additionally, we update the next 
# pointer of the current node to skip the next node and point directly to the node after 
# it, thus effectively removing the next node from the list as well. This approach 
# allows us to delete the given node in constant time without needing to iterate through 
# the entire list.

class Solution:
    def deleteNode(self, node):
        node.val=node.next.val
        node.next=node.next.next