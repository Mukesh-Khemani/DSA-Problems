/*
 * INTUITION:
 * In the problem, we use dynamic programming with binary search optimization. 
 * We maintains an auxiliary array `temp` to store the increasing subsequence, 
 * where `size` keeps track of the current length. We iterate through the input 
 * array `nums`, and for each element, we check if it can extend the existing 
 * subsequence or starts a new one. Binary search is used to efficiently find 
 * the correct position for insertion or replacement.
 */

import java.util.Arrays;

class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] temp = new int[nums.length];
        int size = 1;
        temp[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (temp[size - 1] < nums[i])
                temp[size++] = nums[i];
            else {
                int index = Arrays.binarySearch(temp, 0, size, nums[i]);
                if (index < 0)
                    index = -(index + 1);
                temp[index] = nums[i];
            }
        }
        return size;
    }
}