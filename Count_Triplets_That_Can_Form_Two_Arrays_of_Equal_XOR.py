# INTUITION:
# The core intuition behind this solution is to leverage prefix XOR to count triplets
# that satisfy the condition `arr[i] ^ arr[i+1] ^ ... ^ arr[k] == 0`. By maintaining
# maps (`xor_count_map` and `xor_total_map`) that track the frequency and cumulative
# indices of prefix XOR values encountered so far, the solution avoids the need for a
# brute force approach. The prefix XOR helps in determining if there is a previous
# subarray (from the beginning to some index `j`) which, when XORed with the current
# subarray (from some `j+1` to the current index), results in zero. This approach
# ensures an optimal solution with a time complexity of O(n).

class Solution:
    def countTriplets(self, array: List[int]) -> int:
        n = len(array)
        triplet_count = 0
        current_prefix_xor = 0

        xor_count_map = defaultdict(int)
        xor_count_map[0] = 1
        xor_total_map = defaultdict(int)

        for index in range(n):
            current_prefix_xor ^= array[index]
            triplet_count += xor_count_map[current_prefix_xor] * \
                index - xor_total_map[current_prefix_xor]
            xor_total_map[current_prefix_xor] += index + 1
            xor_count_map[current_prefix_xor] += 1

        return triplet_count
