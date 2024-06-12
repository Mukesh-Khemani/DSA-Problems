# INTUITION:
# The problem aims to sort an array of integers that contains only the values 0, 1, and 2.
# The intuition behind this sorting method is to count the occurrences of each number (0, 1,
# and 2) first and then overwrite the original array with the correct number of 0s, 1s, and
# 2s in ascending order. This ensures that the array is sorted without the need for a more
# complex sorting algorithm, leveraging the fact that there are only three distinct values to
# handle.

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        frequency = [0] * 3
        for number in nums:
            frequency[number] += 1

        index = 0
        for value in range(3):
            nums[index:index + frequency[value]] = [value] * frequency[value]
            index += frequency[value]
