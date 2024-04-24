# INTUITION:
# The Tribonacci sequence is a series of numbers where each number is the sum of
# the three preceding numbers. In this implementation, we handle base cases for
# `n = 0`, `n = 1`, and `n = 2` where the sequence starts with `[0, 1, 1]`. Then,
# we initialize variables `a`, `b`, and `c` to represent the last three elements
# of the sequence. Through iteration, we compute the next number in the sequence
# by summing up `a`, `b`, and `c`, and then updating `a`, `b`, and `c` accordingly.
# Finally, we return the value of `c`, which represents the `n`-th number in the
# Tribonacci sequence. This algorithm efficiently computes the Tribonacci sequence
# without relying on recursion, making it suitable for calculating large `n` values.

class Solution:
    def tribonacci(self, n: int) -> int:
        if (n == 0):
            return 0
        elif (n == 1 or n == 2):
            return 1
        a, b, c = 0, 1, 1
        for i in range(3, n + 1):
            new_number = a + b + c
            a = b
            b = c
            c = new_number
        return c
