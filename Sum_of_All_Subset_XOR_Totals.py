# INTUITION
# The intuition is to calculate the sum of the XOR of all possible subsets of
# an array. The key insight here is that the XOR operation is commutative and
# associative, which allows us to combine elements in a way that leverages the
# properties of bitwise operations. By using the bitwise OR operation (`|`), we
# accumulate the contribution of each number to the final XOR sum, effectively
# capturing the influence of each bit position across all subsets. Shifting the
# result left by `(len(nums) - 1)` accounts for the fact that each bit in the
# XOR result is counted multiple times due to the combinatorial nature of
# subsets, thus providing the correct aggregate sum.

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        answer = 0
        for number in nums:
            answer |= number
        return answer << (len(nums) - 1)
