# INTUITION:
# The intuition behind the solution is to use the given relative order in `arr2` to sort `arr1`
# efficiently. First, we count the occurrences of each element in `arr1` using a frequency array.
# Then, we construct the result array by first adding elements from `arr2` in their specified
# order according to their frequency in `arr1`. After processing all elements of `arr2`, any
# remaining elements in `arr1` (not specified in `arr2`) are added to the result array in ascending
# order. This approach ensures that elements in `arr1` appear first as per the relative order of
# `arr2` and then in ascending order for the rest, while maintaining linear time complexity.


class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        max_val = max(arr1)
        frequency = [0] * (max_val + 1)

        for num in arr1:
            frequency[num] += 1

        sorted_arr = []
        for num in arr2:
            while frequency[num] > 0:
                sorted_arr.append(num)
                frequency[num] -= 1

        for num in range(max_val + 1):
            while frequency[num] > 0:
                sorted_arr.append(num)
                frequency[num] -= 1

        return sorted_arr
