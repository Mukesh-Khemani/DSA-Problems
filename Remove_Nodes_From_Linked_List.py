# INTUITION
# The intuition behind this recursive solution lies in removing nodes from a linked list
# that have values less than the value of their next node. The base case of the recursion
# is when the current node or its next node is null, indicating the end of the list or a
# single node respectively. As the recursive function traverses the list, it moves towards
# the end, ensuring that the current node's value is compared with its next node's value.
# If the current node's value is less than its next node's value, the current node is
# removed by returning the next node, effectively skipping the current node in the list.
# This process continues until the end of the list is reached, and the modified list is returned.

class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        next_node = self.removeNodes(head.next)

        if head.val < next_node.val:
            return next_node

        head.next = next_node
        return head
