# INTUITION:
# The goal is to minimize the number of moves needed to seat students. By calculating
# the differences between the counts of seats and students at each position, we can
# determine how many seats need to be moved to accommodate the students. By iterating
# through these differences and accounting for unmatched seats, we accumulate the total
# number of moves needed.


class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        max_pos = max(max(seats), max(students))
        diffs = [0] * max_pos

        for seat in seats:
            diffs[seat - 1] += 1

        for student in students:
            diffs[student - 1] -= 1

        moves = 0
        unmatched = 0
        for diff in diffs:
            moves += abs(unmatched)
            unmatched += diff

        return moves
