# INTUITION:
# The intuition behind this solution is straightforward: to determine how many students are not in their correct positions
# if the heights were sorted. By comparing the original list of student heights with a sorted version of the same list, we
# can count the number of discrepancies between the two. Each discrepancy represents a student who is out of order. Thus,
# the solution efficiently calculates the number of students who need to move to achieve the sorted order.

class Solution:
    def heightChecker(self, studentHeights: List[int]) -> int:
        return sum(originalHeight != expectedHeight for originalHeight, expectedHeight in zip(studentHeights, sorted(studentHeights)))
