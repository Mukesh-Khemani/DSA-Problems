/*
 * INTUITION:
 * The function aims to make an array of integers, nums, and organize them 
 * into a matrix based on their frequencies. We maintain a frequency array 
 * to track the occurrence of each number and utilizes an ArrayList of Lists 
 * to represent the resulting matrix. For each element in nums, we check if 
 * the frequency of that element is greater than or equal to the current row 
 * index in the matrix. If not, we add a new row to the matrix. We then append 
 * the element to the corresponding row and increments its frequency.
 */

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        int frequency[] = new int[nums.length + 1];
        ArrayList<List<Integer>> ans = new ArrayList<>();
        for (int c : nums) {
            if (frequency[c] >= ans.size())
                ans.add(new ArrayList<>());
            ans.get(frequency[c]).add(c);
            frequency[c]++;
        }
        return ans;
    }
}